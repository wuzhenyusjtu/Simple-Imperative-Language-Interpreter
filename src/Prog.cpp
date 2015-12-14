#include "Prog.h"
#include "global.h"
#include "DeclSeq.h"
#include "StmtSeq.h"
#include "Token.h"
#include "Scanner.h"

Prog::Prog() { declSeq = NULL; stmtSeq = NULL;  }

void Prog::parse()
{
	scanner->nextToken();
	if (scanner->currentToken().getKeyword() == PROGRAM)
	{
		declSeq = new DeclSeq();
		declSeq->parse();
		scanner->nextToken();
		if (scanner->currentToken().getKeyword() == BEGIN)
		{
			stmtSeq = new StmtSeq();
			stmtSeq->parse();
			scanner->nextToken();
			if (scanner->currentToken().getKeyword() == END)
			{
				return;
			}
			else{ cout << "ERROR: Expected \"end\" Keyword!" << endl; exit(0); }
		}
		else{ cout << "ERROR: Expected \"begin\" Keyword!" << endl; exit(0); }
	}
	else{ cout << "ERROR: Expected \"prgram\" Keyword!" << endl; exit(0); }
}

void Prog::print() 
{
	out << "program" << endl;
	declSeq->print(1);
	out << "begin" << endl;
	stmtSeq->print(1);
	out << "end" << endl;
}

void Prog::execute() {
	declSeq->execute();
	stmtSeq->execute();
}