#include "Cmpr.h"
#include "Expr.h"
#include "CmprOp.h"
#include "global.h"
#include "Scanner.h"

Cmpr::Cmpr() { expr1 = NULL; cmprOp = NULL; expr2 = NULL; }

void Cmpr::parse() {
	scanner->nextToken();
	if (scanner->currentToken().getPunctuation() == OPENBRACKET)
	{
		expr1 = new Expr();
		expr1->parse();
		cmprOp = new CmprOp();
		cmprOp->parse();
		expr2 = new Expr();
		expr2->parse();
		scanner->nextToken();
		if (scanner->currentToken().getPunctuation() != CLOSEBRACKET)
			{ cout << "ERROR: Expected ] for the End of Compare!" << endl; exit(0); }
	}
	else{ cout << "ERROR: Expected ] for the End of Compare!" << endl; exit(0); }
}

void Cmpr::print() {
	out << '[';
	expr1->print();
	cmprOp->print();
	expr2->print();
	out << ']';
}

bool Cmpr::evaluate() {
	int value1 = expr1->evaluate(false);
	int value2 = expr2->evaluate(false);
	switch (cmprOp->evaluate())
	{
	case INEQUAL: return value1 != value2; break;
	case EQUAL: return value1 == value2; break;
	case LESS: return value1 < value2; break;
	case LESSEQUAL: return value1 <= value2; break;
	case GREATER: return value1 > value2; break;
	case GREATEREQUAL: return value1 >= value2; break;
	default:
		std::cout << "Bug Identified: Compare Operator Evaluation Failed!" << endl;
		exit(0);
		break;
	}
}