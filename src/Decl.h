#pragma once
#ifndef DECL_H
#define DECL_H
#include <cstdlib>

class IdList;

class Decl {
private:
	IdList *idList;
public:
	Decl();
	void parse();
	void print(int numIndents);
	void execute();
};
#endif