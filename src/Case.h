#pragma once
#ifndef CASE_H
#define CASE_H

#include <string>
#include <cstdlib>

using namespace std;

class CaseletList;
class Expr;
class Scanner;

class Case {
private:
	string identifier; CaseletList *caselet_list; Expr *expr;
public:
	Case();
	void parse();
	void print(int numIndents);
	void execute();
};
#endif