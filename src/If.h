#pragma once
#ifndef IF_H
#define IF_H
#include <cstdlib>

class Cond;
class StmtSeq;

class If {
private:
	Cond *cond; StmtSeq *thenStmtSeq; StmtSeq *elseStmtSeq;
public:
	If();
	void parse();
	void print(int numIndents);
	void execute();
};
#endif