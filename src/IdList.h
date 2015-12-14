#pragma once
#ifndef IDLIST_H
#define IDLIST_H
#include <cstdlib>

class Identifier;

class IdList {
private:
	Identifier *id; IdList *idList;
public:
	IdList();
	void parse();
	void print();
	void inputExecute();
	void outputExecute();
	void declExecute();
};
#endif