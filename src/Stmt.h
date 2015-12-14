#pragma once
#ifndef STMT_H
#define STMT_H
#include <cstdlib>

class Assign;
class If;
class In;
class Out;
class Case;
class Loop;

class Stmt {
private:
	int altNo;
	Assign *assignStmt; If *ifStmt; Loop *loopStmt; In *inStmt; Out *outStmt; Case *caseStmt;
public:
	Stmt();
	void parse();
	void print(int numIndents);
	void execute();
};
#endif