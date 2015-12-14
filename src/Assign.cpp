#include "Assign.h"
#include "Scanner.h"
#include "Expr.h"
#include "Identifier.h"
#include "global.h"
#include "Token.h"
#include "Scanner.h"
#include <string>

Assign::Assign()
{
	id = NULL; expr = NULL;
}

void Assign::parse() {
	scanner->nextToken();
	if (scanner->currentToken().getType() == IDENTIFIER)
	{
		scanner->prevToken();
		id = new Identifier();
		id->parse();
		scanner->nextToken();
		if (scanner->currentToken().getType() == ASSIGNOPERATOR)
		{
			expr = new Expr();
			expr->parse();
		}
		else{ cout << "ERROR: Expected := for an Assign Statement!" << endl; exit(0); }
		scanner->nextToken();
		if (scanner->currentToken().getPunctuation() != SEMICOLON)
			{ cout << "ERROR: Expected \";\" for the End of an Assign Statement!" << endl; exit(0); }
	}
	else{ cout <<"ERROR: Expected an Identifier for an Assign Statment!" << endl; exit(0); }
}

void Assign::print(int numIndents) {
	out << std::string(numIndents, '\t');
	id->print();
	out << ":=";
	expr->print();
	out << ';' << endl;
}

void Assign::execute() {
	int value = expr->evaluate(false);
	id->assignExecute(value);
}