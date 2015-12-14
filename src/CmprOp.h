#pragma once
#ifndef CMPROP_H
#define CMPROP_H

#include <cstdlib>
#include "Token.h"

class CmprOp {
private:
	CmprOperator opr;
public:
	CmprOp();
	void parse();
	void print();
	CmprOperator evaluate();
};
#endif
