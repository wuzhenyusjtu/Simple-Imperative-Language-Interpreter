#pragma once
#ifndef COND_H
#define COND_H

#include "Token.h"
#include <cstdlib>

class Cmpr;
class Cond;
enum LogicOperator;

class Cond {
private:
	Cmpr *cmpr; Cond *cond1; Cond *cond2; LogicOperator opr;
public:
	Cond();
	void parse();
	void print();
	bool evaluate();
};
#endif