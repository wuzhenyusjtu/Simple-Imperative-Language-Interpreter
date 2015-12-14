#pragma once
#ifndef LOOP_H
#define LOOP_H
#include <cstdlib>

class StmtSeq;
class Cond;

class Loop {
private:
	StmtSeq *stmtSeq; Cond *cond;
public:
	Loop();
	void parse();
	void print(int numIndents);
	void execute();
};
#endif