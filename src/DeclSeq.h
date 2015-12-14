#pragma once
#ifndef DECLSEQ_H
#define DECLSEQ_H
#include <cstdlib>

class Decl;

class DeclSeq {
private:
	Decl *decl; DeclSeq *declSeq;
public:
	DeclSeq();
	void parse();
	void print(int numIndents);
	void execute();
};
#endif