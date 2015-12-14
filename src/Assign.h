#pragma once
#ifndef ASSIGN_H
#define ASSIGN_H
#include <cstdlib>

class Expr;
class Identifier;

class Assign {
private:
	Identifier *id; Expr *expr;
public:
	Assign();
	void parse();
	void print(int numIndents);
	void execute();
};
#endif