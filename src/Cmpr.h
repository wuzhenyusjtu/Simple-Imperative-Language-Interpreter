#pragma once
#ifndef CMPR_H
#define CMPR_H
#include <cstdlib>

class Expr;
class CmprOp;

class Cmpr {
private:
	Expr *expr1; CmprOp *cmprOp; Expr *expr2;
public:
	Cmpr();
	void parse();
	void print();
	bool evaluate();
};
#endif