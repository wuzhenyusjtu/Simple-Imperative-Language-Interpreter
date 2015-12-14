#include "Identifier.h"
#include "global.h"
#include <stdexcept>
#include "Scanner.h"
#include <map>
#include "IdentifierMap.h"

Identifier::Identifier() { literal = ""; }

void Identifier::parse() {
	scanner->nextToken();
	if (scanner->currentToken().getType() == IDENTIFIER)
	{
		literal = scanner->currentToken().getLiteral();
	}
	else{ cout <<"ERROR: Expected an Identifier!" << endl; exit(0); }
}

void Identifier::print() {
	out << literal;
}

void Identifier::declExecute(){
	identifierMap->insertKey(literal);
}

void Identifier::assignExecute(int value) {
	identifierMap->setValue(literal, value);
}

void Identifier::inputExecute() {
	identifierMap->setValue(literal, scanner->getNextValue());
}

void Identifier::outputExecute() {
	out << identifierMap->getValue(literal) << endl;
}

int Identifier::evaluate() {
	return identifierMap->getValue(literal);
}