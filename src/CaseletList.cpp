#include "CaseletList.h"
#include "Caselet.h"
#include "Token.h"
#include "global.h"
#include "Scanner.h"

CaseletList::CaseletList() { caselet = NULL; caseletList = NULL; }

void CaseletList::parse() {
	caselet = new Caselet();
	caselet->parse();
	scanner->nextToken();
	if (scanner->currentToken().getPunctuation() == BAR)
	{
		caseletList = new CaseletList();
		caseletList->parse();
	}
	else scanner->prevToken();
}

void CaseletList::print(int numIndents, bool isHead){
	if(isHead)
	{
		caselet->print(numIndents, true);
	}
	else caselet->print(numIndents, false);
	if (caseletList != NULL) {
		caseletList->print(numIndents, false);
	}
}

bool CaseletList::execute(std::string identifier) {
	if (!caselet->execute(identifier)){
		if (caseletList != NULL)
			return caseletList->execute(identifier);
		else return false;
	}
	else return true;
}