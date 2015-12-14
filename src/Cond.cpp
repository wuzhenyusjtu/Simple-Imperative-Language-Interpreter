#include "Cond.h"
#include "Scanner.h"
#include "Cmpr.h"
#include "global.h"

Cond::Cond() { cmpr = NULL; cond1 = NULL; cond2 = NULL; }


void Cond::parse() {
	scanner->nextToken();
	if (scanner->currentToken().getPunctuation() == OPENBRACKET)
	{
		scanner->prevToken();
		cmpr = new Cmpr();
		cmpr->parse();
		
		return;
	}
	else if (scanner->currentToken().getPunctuation() == OPENPARENTHESIS)
	{
		cond1 = new Cond();
		cond1->parse();
		scanner->nextToken();
		if (scanner->currentToken().getLogicOperator() == AND)
		{
			opr = AND;
			cond2 = new Cond();
			cond2->parse();
		}
		else if (scanner->currentToken().getLogicOperator() == OR)
		{
			opr = OR;
			cond2 = new Cond();
			cond2->parse();
		}
		else{ cout << "ERROR: Expected Logic Operator!" << endl; exit(0); }
		scanner->nextToken();
		if (scanner->currentToken().getPunctuation() != CLOSEPARENTHESIS)
		{cout << "ERROR: Expected an Closingparenthesis!" << endl; exit(0);}
		return;
	}
	else if (scanner->currentToken().getLogicOperator() == NOT)
	{
		opr = NOT;
		cond1 = new Cond();
		cond1->parse();
		return;
	}
	else{ cout << "ERROR: Unexpected Token for Cond Statement!" << endl; exit(0); }
}

void Cond::print() {	
	if (cmpr != NULL) cmpr->print();
	else
	{
		switch (opr)
		{
		case NOT:
			out << '!';
			cond1->print();
			break;
		case AND:
			out << '(';
			cond1->print();
			out << "AND";
			cond2->print();
			out << ')';
			break;
		case OR:
			out << '(';
			cond1->print();
			out << "OR";
			cond2->print();
			out << ')';
			break;
		default:
			{ cout <<"ERROR: Logic Operator Unmatched!" << endl; exit(0); }
			break;
		}
	}
}

bool Cond::evaluate() {
	if (cmpr != NULL)
	{
		return cmpr->evaluate();
	}
	else {
		if (cond2 == NULL)
		{
			return !cond1->evaluate();
		}
		else {
			bool value1 = cond1->evaluate();
			bool value2 = cond2->evaluate();
			if (opr == OR)
			{
				return value1 || value2;
			}
			else
			{
				return value1 && value2;
			}
		}
	}
}