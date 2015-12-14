#pragma once
#ifndef TERM_H
#define TERM_H
#include <cstdlib>

class Factor;

class Term {
private:
	Factor *factor; Term *term;
public:
	Term();
	void parse();
	void print();
	int evaluate();
};
#endif