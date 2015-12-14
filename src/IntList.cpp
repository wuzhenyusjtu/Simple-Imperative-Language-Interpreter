#include "IntList.h"
#include "global.h"
#include <stdexcept>
#include "Scanner.h"

IntList::IntList() {  integer = 0; intlist = NULL; }

void IntList::parse() {
	scanner->nextToken();
	if (scanner->currentToken().getArithOperator() == MINUSSIGN) {
		scanner->nextToken();
		if (scanner->currentToken().getType() == CONSTANT)
		{
			integer = atoi(scanner->currentToken().getLiteral().c_str())*(-1);
		}
		else{ cout << "ERROR: Expected Constant Value" << endl; exit(0); }
	}
	else {
		if (scanner->currentToken().getType() == CONSTANT)
		{
			integer = atoi(scanner->currentToken().getLiteral().c_str());
		}
		else{ cout <<"ERROR: Expected Constant Value" << endl; exit(0); }
	}
	scanner->nextToken();
	if (scanner->currentToken().getPunctuation() == COMMA)
	{
		intlist = new IntList();
		intlist->parse();
	}
	else scanner->prevToken();
}


void IntList::print() {
	out << integer;
	if (intlist != NULL) {
		out << ',';
		intlist->print();
	}
}

std::vector<int> IntList::evaluate() {
	std::vector<int> temp;
	if (intlist !=NULL)
	{
		temp = intlist->evaluate();
	}
	else temp = std::vector<int>();
	temp.push_back(integer);
	return temp;
}