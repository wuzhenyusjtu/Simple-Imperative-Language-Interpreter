#pragma once
#ifndef OUT_H
#define OUT_H
#include <cstdlib>

class IdList;

class Out {
private:
	IdList *idList;
public:
	Out();
	void parse();
	void print(int numIndents);
	void evecute();
};
#endif