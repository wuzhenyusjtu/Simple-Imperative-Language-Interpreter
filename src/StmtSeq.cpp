#include "StmtSeq.h"
#include "global.h"
#include "Token.h"
#include "Stmt.h"
#include "Scanner.h"


StmtSeq::StmtSeq() { stmt = NULL; stmtSeq = NULL;  }

void StmtSeq::parse() {
	stmt = new Stmt();
	stmt->parse();
	scanner->nextToken();
	if(scanner->currentToken().getType() == MYEOF) { scanner->prevToken(); return;}
	Keyword keyword = scanner->currentToken().getKeyword();
	if (keyword != END && keyword != ENDIF && keyword != ELSE && keyword != WHILE)
	{
		scanner->prevToken();
		stmtSeq = new StmtSeq();
		stmtSeq->parse();
		return;
	}
	else {
		scanner->prevToken();
		return;
	}
}

void StmtSeq::print(int numIndents) {
	stmt->print(numIndents);
	if (stmtSeq != NULL)
		stmtSeq->print(numIndents);
}

void StmtSeq::execute() {
	stmt->execute();
	if (stmtSeq != NULL)
	{
		stmtSeq->execute();
	}
}