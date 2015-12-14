#pragma once
#ifndef CASELETLIST_H
#define CASELETLIST_H
#include <string>
#include <cstdlib>

class Caselet;

class CaseletList {
private:
	Caselet *caselet; CaseletList *caseletList;
public:
	CaseletList();
	void parse();
	void print(int numIndents, bool isHead);
	bool execute(std::string identifier);
};
#endif