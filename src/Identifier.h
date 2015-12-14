#pragma once
#ifndef IDENTIFIER_H
#define IDENTITIER_H

#include <string>
#include "global.h"
#include <cstdlib>

using namespace std;


class Identifier {
private:
	string literal;
public:
	Identifier();
	void parse();
	void print();
	void declExecute();
	void assignExecute(int value);
	void inputExecute();
	void outputExecute();
	int evaluate();

};
#endif