#include "IdList.h"
#include "Token.h"
#include "Identifier.h"
#include "global.h"
#include <stdexcept>
#include "Scanner.h"

IdList::IdList() { id = NULL; idList = NULL; }



void IdList::parse() {
	scanner->nextToken();
	if (scanner->currentToken().getType() == IDENTIFIER)
	{
		scanner->prevToken();
		id = new Identifier();
		id->parse();
		scanner->nextToken();
		if (scanner->currentToken().getPunctuation() == COMMA)
		{
			idList = new IdList();
			idList->parse();
			return;
		}
		else {
			if (scanner->currentToken().getPunctuation() != SEMICOLON){ cout <<"ERROR: Expected; for a Statement!" << endl; exit(0); }
			return;
		}
	}
	else{ cout << "ERROR: Expected Identifier!" << endl; exit(0); }

}

void IdList::print() {
	id->print();
	if (idList != NULL) {
		out << ',';
		idList->print();
	}
}

void IdList::inputExecute() {
	id->inputExecute();
	if (idList != NULL){
		idList->inputExecute();
	}
}

void IdList::outputExecute() {
	id->outputExecute();
	if (idList != NULL){
		idList->outputExecute();
	}
}

void IdList::declExecute() {
	id->declExecute();
	if (idList != NULL) {
		idList->declExecute();
	}
}