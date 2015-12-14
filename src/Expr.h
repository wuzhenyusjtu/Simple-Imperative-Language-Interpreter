#pragma once
#ifndef EXPR_H
#define EXPR_H
#include "Token.h"
#include <cstdlib>

class Term;

class Expr {
private:
	Term *term; Expr *expr;
	ArithOperator opr;
public:
	Expr();
	void parse();
	void print();
	int evaluate(bool);
};
#endif