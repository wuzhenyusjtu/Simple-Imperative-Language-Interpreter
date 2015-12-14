#pragma once
#ifndef CONST_H
#define CONST_H

#include <string>
#include <cstdlib>

class Const {
private:
	int value;
public:
	Const();
	void parse();
	void print();
	int evaluate();
};
#endif