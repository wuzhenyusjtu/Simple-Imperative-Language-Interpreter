#include "Case.h"
#include "Scanner.h"
#include "Token.h"
#include "CaseletList.h"
#include "Expr.h"
#include "global.h"
#include "IdentifierMap.h"

Case::Case() { caselet_list = NULL; expr = NULL; identifier = ""; }


void Case::parse() {
	scanner->nextToken();
	if (scanner->currentToken().getKeyword() == CASE)
	{
		scanner->nextToken();
		if (scanner->currentToken().getType() == IDENTIFIER)
		{
			identifier = scanner->currentToken().getLiteral();
			scanner->nextToken();
			if (scanner->currentToken().getKeyword() == OF)
			{
				caselet_list = new CaseletList();
				caselet_list->parse();
				scanner->nextToken();
				if (scanner->currentToken().getKeyword() == ELSE)
				{
					expr = new Expr();
					expr->parse();
					scanner->nextToken();
					if (scanner->currentToken().getKeyword() != END){
						cout << "Expected \"end\" Keyword!" << endl; 
						exit(0);
					}
					scanner->nextToken();
					if (scanner->currentToken().getPunctuation() == SEMICOLON) {}
					else{ cout << "Expected \";\" for case statmenet!" << endl; exit(0); }
				}
				else{ cout << "ERROR: Expected \"else\" Keyword!" << endl; exit(0); }
			}
			else{ cout << "ERROR: Expected \"of\" Keyword!" << endl; exit(0); }
		}
		else{ cout << "ERROR: Expected Identifier!" << endl; exit(0); }
	}
	else{ cout << "ERROR: Expected \"Case\"!" << endl; exit(0); }
}

void Case::print(int numIndents) {
	out << std::string(numIndents, '\t');
	out << "case" << ' ' << identifier << ' '<< "of" << endl;
	caselet_list->print(numIndents+1, true);
	out << std::string(numIndents+1, '\t'); 
	out << "else" << ' ';
	expr->print();
	out << endl;
	out << std::string(numIndents, '\t');
	out << "end" << ';' << endl;
}

void Case::execute() {
	if (!caselet_list->execute(identifier))
	{
		identifierMap->setValue(identifier, expr->evaluate(false));
	}
}