#include "Stmt.h"
#include "Token.h"
#include "global.h"
#include "If.h"
#include "Loop.h"
#include "In.h"
#include "Out.h"
#include "Case.h"
#include "Assign.h"
#include "Scanner.h"

Stmt::Stmt() {  altNo = 0; assignStmt = NULL; ifStmt = NULL; loopStmt = NULL; inStmt = NULL; outStmt = NULL; caseStmt = NULL; }


void Stmt::parse() {
	scanner->nextToken();
	if (scanner->currentToken().getType() == KEYWORD)
	{
		switch (scanner->currentToken().getKeyword())
		{
		case IF: altNo = 1; scanner->prevToken(); ifStmt = new If(); ifStmt->parse(); break;
		case DO: altNo = 2; scanner->prevToken(); loopStmt = new Loop(); loopStmt->parse(); break;
		case INPUT: altNo = 3; scanner->prevToken(); inStmt = new In(); inStmt->parse(); break;
		case OUTPUT: altNo = 4; scanner->prevToken(); outStmt = new Out(); outStmt->parse(); break;
		case CASE: altNo = 5; scanner->prevToken(); caseStmt = new Case(); caseStmt->parse(); break;
		default:
			cout <<"ERROR: Expected a Valid Statement!" << endl; 
			exit(0);
			break;
		}
		return;
	}
	else if (scanner->currentToken().getType() == IDENTIFIER) {
		altNo = 0;
		scanner->prevToken();
		assignStmt = new Assign();
		assignStmt->parse();
		return;
	}
	else{ cout << "ERROR: Expected Statement!" << endl; exit(0); }
}

void Stmt::print(int numIndents) {
	switch (altNo){
	case 0: assignStmt->print(numIndents); break;
	case 1: ifStmt->print(numIndents); break;
	case 2: loopStmt->print(numIndents); break;
	case 3: inStmt->print(numIndents); break;
	case 4: outStmt->print(numIndents); break;
	case 5: caseStmt->print(numIndents); break;
	default:
		cout << "ERROR: No Statement Matched for Printing!" << endl; 
		exit(0);
		break;
	}
}

void Stmt::execute() {
	switch (altNo) {
	case 0: assignStmt->execute(); break;
	case 1: ifStmt->execute(); break;
	case 2: loopStmt->execute(); break;
	case 3: inStmt->execute(); break;
	case 4: outStmt->evecute(); break;
	case 5: caseStmt->execute(); break;
	default:
		cout << "Bug Identified: No Statement Matched for Executing!" << endl;
		exit(0);
		break;
	}
}