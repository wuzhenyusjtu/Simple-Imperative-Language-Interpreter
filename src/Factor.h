#pragma once
#ifndef FACTOR_H
#define FACTOR_H
#include <cstdlib>

class Const;
class Factor;
class Expr;
class Identifier;

class Factor {
private:
	Const *constant; Identifier *id; Factor *factor; Expr *expr;
public:
	Factor();
	void parse();
	void print();
	int evaluate();
};
#endif