#include "Term.h"
#include "Factor.h"
#include "Term.h"
#include "global.h"
#include "Scanner.h"

Term::Term() {  factor = NULL; term = NULL; }


void Term::parse() {
	factor = new Factor();
	factor->parse();
	scanner->nextToken();
	if (scanner->currentToken().getArithOperator() == MULTSIGN)
	{
		term = new Term();
		term->parse();
		return;
	}
	else {
		scanner->prevToken();
		return;
	}
}

void Term::print() {
	factor->print();
	if (term != NULL) {
		out << '*';
		term->print();
	}
}

int Term::evaluate() {
	int factorValue = factor->evaluate();
	if (term != NULL) {
		return factorValue * term->evaluate();
	}
	return factorValue;
}