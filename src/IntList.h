#pragma once
#ifndef INTLIST_H
#define INTLIST_H
#include <vector>
#include <cstdlib>

class IntList {
private:
	int integer; IntList *intlist;
public:
	IntList();
	void parse();
	void print();
	std::vector<int> evaluate();
};

#endif