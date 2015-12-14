#include "Expr.h"
#include "Term.h"
#include "global.h"
#include "Scanner.h"

Expr::Expr() { term = NULL; opr = ANONE;  expr = NULL; }


void Expr::parse() {
	term = new Term();
	term->parse();
	scanner->nextToken();
	if (scanner->currentToken().getArithOperator() == PLUSSIGN)
	{
		opr = PLUSSIGN;
		expr = new Expr();
		expr->parse();
		return;
	}
	else if (scanner->currentToken().getArithOperator() == MINUSSIGN)
	{
		opr = MINUSSIGN;
		expr = new Expr();
		expr->parse();
		return;
	}
	else {
		scanner->prevToken();
		return;
	}
}

void Expr::print() {
	term->print();
	switch (opr)
	{
	case ANONE:
		return;
		break;
	case PLUSSIGN:
		out << '+';
		expr->print();
		break;
	case MINUSSIGN:
		out << '-';
		expr->print();
		break;
	default:
		{ cout << "ERROR: No Arithmetic Sign Matched!" << endl; exit(0); }
		break;
	}
}

int Expr::evaluate(bool isChangeSign) {
	int termValue = term->evaluate();
	int exprValue;
	switch (opr)
	{
	case ANONE:
		return termValue;
		break;
	case PLUSSIGN:
		exprValue = expr->evaluate(false);
		if (isChangeSign) return termValue - exprValue;
		else return termValue + exprValue;
		break;
	case MINUSSIGN:
		exprValue = expr->evaluate(true);
		if (isChangeSign) return termValue + exprValue;
		else return termValue - exprValue;
		break;
	default:
		{ cout << "ERROR: No Arithmetic Sign Matched!" << endl; exit(0); }
		break;
	}
}