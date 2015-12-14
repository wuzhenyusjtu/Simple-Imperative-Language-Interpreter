#include "CmprOp.h"
#include "Scanner.h"
#include "global.h"

CmprOp::CmprOp() { opr = CNONE; }

void CmprOp::parse() {
	scanner->nextToken();
	opr = scanner->currentToken().getCmprOperator();
}

void CmprOp::print(){
	switch (opr)
	{
	case INEQUAL:
		out << "!=";
		break;
	case EQUAL:
		out << '=';
		break;
	case LESS:
		out << '<';
		break;
	case LESSEQUAL:
		out << "<=";
		break;
	case GREATER:
		out << '>';
		break;
	case GREATEREQUAL:
		out << ">=";
		break;
	default:
		{ cout << "ERROR: Compare Operator Unmatched" << endl; exit(0); }
		break;
	}
}

CmprOperator CmprOp::evaluate() {
	return opr;
}