#include "DeclSeq.h"
#include "Scanner.h"
#include "Decl.h"
#include "Token.h"
#include "global.h"

DeclSeq::DeclSeq() { decl = NULL; declSeq = NULL; }


void DeclSeq::parse() {
	decl = new Decl();
	decl->parse();
	scanner->nextToken();
	if(scanner->currentToken().getType() == MYEOF) {scanner->prevToken(); return;}
	if (scanner->currentToken().getKeyword() != BEGIN)
	{
		scanner->prevToken();
		declSeq = new DeclSeq();
		declSeq->parse();
		return;
	}
	else {
		scanner->prevToken();
		return;
	}
}

void DeclSeq::print(int numIndents) {
	decl->print(numIndents);
	if (declSeq != NULL)
		declSeq->print(numIndents);
}

void DeclSeq::execute() {
	decl->execute();
	if (declSeq!=NULL){
		declSeq->execute();
	}
}