#pragma once
#ifndef PROG_H
#define PROG_H

#include <cstdlib>
#include <iostream>

class DeclSeq;
class StmtSeq;

class Prog {
private:
	DeclSeq *declSeq; StmtSeq *stmtSeq;
public:
	Prog();
	void parse();
	void print();
	void execute();
};
#endif