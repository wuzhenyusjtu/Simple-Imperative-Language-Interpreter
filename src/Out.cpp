#include "Out.h"
#include "global.h"
#include "IdList.h"
#include <stdexcept>
#include "Scanner.h"

Out::Out() {  idList = NULL; }


void Out::parse() {
	scanner->nextToken();
	if (scanner->currentToken().getKeyword() == OUTPUT)
	{
		idList = new IdList();
		idList->parse();
		return;
	}
	else
	{
		{ cout << "ERROR: Expected \"output\" Keyword!" << endl; exit(0); }
	}
}

void Out::print(int numIndents) {
	out << std::string(numIndents, '\t');
	out << "output" << ' ';
	idList->print();
	out << ';' << endl;
}

void Out::evecute() {
	idList->outputExecute();
}