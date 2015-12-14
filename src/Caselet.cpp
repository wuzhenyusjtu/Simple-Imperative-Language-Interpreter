#include "Caselet.h"
#include "Expr.h"
#include "IntList.h"
#include "Scanner.h"
#include "Token.h"
#include "global.h"
#include "IdentifierMap.h"

Caselet::Caselet() {intList = NULL; expr = NULL; }


void Caselet::parse() {
	intList = new IntList();
	intList->parse();
	scanner->nextToken();
	if (scanner->currentToken().getPunctuation() == COLON)
	{
		expr = new Expr();
		expr->parse();
	}
	else{ cout <<"Expected : for a CaseLet Seperator!" << endl; exit(0); }
}

void Caselet::print(int numIndents, bool isHead) {
	out << std::string(numIndents, '\t');
	if(!isHead)
	{
		out << '|';
	}
	intList->print();
	out << ':';
	expr->print();
	out << endl;
}

bool Caselet::execute(std::string identifier) {
	vector<int> ivec = intList->evaluate();
	//for(size_t i = 0; i < ivec.size(); ++i)
	//{
	//	std::cout << ivec[i] << std::endl;
	//}
	int value = identifierMap->getValue(identifier);
	if (std::find(ivec.begin(), ivec.end(), value) != ivec.end())
	{
		identifierMap->setValue(identifier, expr->evaluate(false));
		return true;
	}
	else return false;
}