#include "If.h"
#include "Cond.h"
#include "StmtSeq.h"
#include "global.h"
#include <stdexcept>
#include "Scanner.h"


If::If() { thenStmtSeq = NULL; elseStmtSeq = NULL; }

void If::parse() {
	scanner->nextToken();
	if (scanner->currentToken().getKeyword() == IF)
	{
		cond = new Cond();
		cond->parse();
		scanner->nextToken();
		if (scanner->currentToken().getKeyword() == THEN)
		{
			thenStmtSeq = new StmtSeq();
			thenStmtSeq->parse();
			scanner->nextToken();
			if (scanner->currentToken().getKeyword() == ELSE)
			{
				elseStmtSeq = new StmtSeq();
				elseStmtSeq->parse();
				scanner->nextToken();
				if (scanner->currentToken().getKeyword() != ENDIF)
					{ cout << "ERROR: Expected \"endif\" Keyword for If Statement!" << endl; exit(0); }
				scanner->nextToken();
				if (scanner->currentToken().getPunctuation() != SEMICOLON)
					{ cout << "ERROR: Expected \";\" for a Statement!" << endl; exit(0); }
			}
			else if (scanner->currentToken().getKeyword() == ENDIF)
			{
				scanner->nextToken();
				if (scanner->currentToken().getPunctuation() != SEMICOLON)
					{ cout << "ERROR: Expected \";\" for a Statement!" << endl; exit(0); }
			}
			else{ cout << "ERROR: Expected \"endif\" Keyword" << endl; exit(0); }
		}
		else{ cout << "ERROR: Expected \"then\" Keyword!" << endl; exit(0); }
	}
	else{ cout << "ERROR: Expected \"if\" Keyword!" << endl; exit(0); }
}

void If::print(int numIndents) {
	out << std::string(numIndents, '\t');
	out << "if";
	cond->print();
	out << "then" << endl;
	thenStmtSeq->print(numIndents+1);
	if (elseStmtSeq!=NULL)
	{
		out << std::string(numIndents, '\t');
		out << "else" << endl;
		elseStmtSeq->print(numIndents+1);
	}
	out << std::string(numIndents, '\t');
	out << "endif" << ';' << endl;
}

void If::execute() {
	if (cond->evaluate())
	{
		thenStmtSeq->execute();
	}
	else {
		if (elseStmtSeq != NULL){
			elseStmtSeq->execute();
		}
	}
}