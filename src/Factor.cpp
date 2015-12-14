#include "Factor.h"
#include "Identifier.h"
#include "Token.h"
#include "Expr.h"
#include "Const.h"
#include "global.h"
#include "Scanner.h"


Factor::Factor() {  constant = NULL; id = NULL; factor = NULL; expr = NULL; }

void Factor::parse() {
	scanner->nextToken();
	switch (scanner->currentToken().getType())
	{
	case CONSTANT: scanner->prevToken(); constant = new Const(); constant->parse(); break;
	case IDENTIFIER: scanner->prevToken(); id = new Identifier(); id->parse(); break;
	case ARITHOPERATOR:
		if (scanner->currentToken().getArithOperator() == MINUSSIGN)
		{
			factor = new Factor();
			factor->parse();
		}
		break;
	case PUNCTUATION:
		if (scanner->currentToken().getPunctuation() == OPENPARENTHESIS)
		{
			expr = new Expr();
			expr->parse();
		}
		else{ cout << "ERROR: Expected an Openingparenthesis!" << endl; exit(0); }
		scanner->nextToken();
		if (scanner->currentToken().getPunctuation() != CLOSEPARENTHESIS)
		{cout << "ERROR: Expected an Closingparenthesis!" << endl; exit(0);}
		break;
	default:
		{ cout << "ERROR: Expected a Factor Statement" << endl; exit(0); }
		break;
	}
}

void Factor::print() {
	if (constant!=NULL){
		constant->print();
	}
	if (id!=NULL)
	{
		id->print();
	}
	if (factor!=NULL)
	{
		factor->print();
	}
	if (expr!=NULL)
	{
		expr->print();
	}
}

int Factor::evaluate() {
	if (constant != NULL) {
		return constant->evaluate();
	}
	if (id != NULL)
	{
		return id->evaluate();
	}
	if (factor != NULL)
	{
		return -1*(factor->evaluate());
	}
	if (expr != NULL)
	{
		return expr->evaluate(false);
	}
}