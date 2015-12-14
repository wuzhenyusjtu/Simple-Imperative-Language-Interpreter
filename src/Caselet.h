#pragma once
#ifndef CASELET_H
#define CASELET_H
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>

class IntList;
class Expr;

class Caselet {
private:
	IntList *intList; Expr *expr;
public:
	Caselet();
	void parse();
	void print(int numIndents, bool isHead);
	bool execute(std::string identifier);
};
#endif