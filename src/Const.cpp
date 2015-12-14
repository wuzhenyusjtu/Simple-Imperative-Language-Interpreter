#include "Const.h"
#include "global.h"
#include "Scanner.h"

Const::Const(){ value = 0; }

void Const::parse() {
	scanner->nextToken();
	if (scanner->currentToken().getType() == CONSTANT)
	{
		string literal = scanner->currentToken().getLiteral();
		value = atoi(literal.c_str());
		return;
	}
	else throw("ERROR: Expected Constant Value!");
}

void Const::print() {
	out << value;
}

int Const::evaluate() {
	return value;
}