#include "In.h"
#include "global.h"
#include "IdList.h"
#include "Scanner.h"
#include "IdentifierMap.h"


In::In() {  idList = NULL; }

void In::parse() {
	scanner->nextToken();
	if (scanner->currentToken().getKeyword() == INPUT)
	{
		idList = new IdList();
		idList->parse();
		return;
	}
	else { cout << "ERROR: Expected \"input\" Keyword!" << endl; exit(0); }
}

void In::print(int numIndents) {
	out << std::string(numIndents, '\t');
	out << "input" << ' ';
	idList->print();
	out << ';' << endl;
}

void In::execute() {
	idList->inputExecute();
}