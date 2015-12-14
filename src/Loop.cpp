#include "Loop.h"
#include "global.h"
#include "StmtSeq.h"
#include "Cond.h"
#include <stdexcept>
#include "Scanner.h"


Loop::Loop() {  stmtSeq = NULL; cond = NULL; }

void Loop::parse() {
	scanner->nextToken();
	if (scanner->currentToken().getKeyword() == DO)
	{
		stmtSeq = new StmtSeq();
		stmtSeq->parse();
		scanner->nextToken();
		if (scanner->currentToken().getKeyword() == WHILE)
		{
			cond = new Cond();
			cond->parse();
			scanner->nextToken();
			if (scanner->currentToken().getKeyword() != ENDDO)
				{ cout <<"ERROR: Expected \"enddo\" Keyword!" << endl; exit(0); }
			scanner->nextToken();
			if (scanner->currentToken().getPunctuation() != SEMICOLON)
				{ cout << "ERROR: Expected \";\" for Do-While Statement!" << endl; exit(0); }
		}
		else{ cout << "ERROR: Expected \"while\" Keyword!" << endl; exit(0); }
	}
	else{ cout << "ERROR: Expected \"do\" Keyword!" << endl; exit(0); }
}

void Loop::print(int numIndents) {
	out << std::string(numIndents, '\t');
	out << "do" << endl;
	stmtSeq->print(numIndents+1);
	out << std::string(numIndents, '\t');
	out << "while";
	cond->print();
	out << "enddo" << ';'<<endl;	
}

void Loop::execute() {
	do
	{
		stmtSeq->execute();
	} while (cond->evaluate());	
}