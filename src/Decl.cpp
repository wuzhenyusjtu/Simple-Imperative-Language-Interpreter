#include "Decl.h"
#include "IdList.h"
#include "global.h"
#include "Scanner.h"

Decl::Decl() { idList = NULL; }


void Decl::parse() {
	scanner->nextToken();
	if (scanner->currentToken().getKeyword() == INT)
	{
		idList = new IdList();
		idList->parse();
		return;
	}
	else{ cout << "ERROR: Expected \"int\" Keyword!" << endl; exit(0); }
}

void Decl::print(int numIndents) {
	out << std::string(numIndents, '\t') << "int" << ' ';
	idList->print();
	out << ';' << endl;
}

void Decl::execute() {
	idList->declExecute();
}