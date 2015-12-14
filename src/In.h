#pragma once
#ifndef IN_H
#define IN_H
#include <cstdlib>

class IdList;

class In {
private:
	IdList *idList;
public:
	In();
	void parse();
	void print(int numIndents);
	void execute();
};
#endif