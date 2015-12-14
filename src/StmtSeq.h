#pragma once
#ifndef STMTSEQ_H
#define STMTSEQ_H
#include <cstdlib>

class Stmt;

class StmtSeq {
private:
	Stmt *stmt; StmtSeq *stmtSeq;
public:
	StmtSeq();
	void parse();
	void print(int numIndents);
	void execute();
};
#endif