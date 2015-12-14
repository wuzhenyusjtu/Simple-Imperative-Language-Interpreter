#pragma once
#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <cstdlib>

using namespace std;

enum TokenType {TNONE, KEYWORD, PUNCTUATION, ARITHOPERATOR, CMPROPERATOR, LOGICOPERATOR, ASSIGNOPERATOR, IDENTIFIER, CONSTANT, MYEOF};
enum Keyword {KNONE, PROGRAM, BEGIN, END, INT, INPUT, OUTPUT, IF, THEN, ELSE, ENDIF, DO, WHILE, ENDDO, CASE, OF};
enum Punctuation {PNONE, SEMICOLON, COMMA, OPENPARENTHESIS, CLOSEPARENTHESIS, OPENBRACKET, CLOSEBRACKET, COLON, BAR};
enum ArithOperator {ANONE, PLUSSIGN, MINUSSIGN, MULTSIGN};
enum CmprOperator {CNONE, INEQUAL, EQUAL, LESS, LESSEQUAL, GREATER, GREATEREQUAL};
enum LogicOperator {LNONE, NOT, AND, OR};


class Token
{
private:
	string literal;
	TokenType tokenType;
	Keyword keyword;
	Punctuation punctuation;
	ArithOperator arithOperator;
	CmprOperator cmprOperator;
	LogicOperator logicOperator;
public:
	Token(string literal, TokenType tokentype);
	Token(string literal, TokenType tokentype, Keyword keyword);
	Token(string literal, TokenType tokentype, Punctuation punctuation);
	Token(string literal, TokenType tokentype, ArithOperator arithOperator);
	Token(string literal, TokenType tokentype, CmprOperator cmprOperator);
	Token(string literal, TokenType tokentype, LogicOperator logicOperator);
	string getLiteral();
	TokenType getType();
	Keyword getKeyword();
	Punctuation getPunctuation();
	ArithOperator getArithOperator();
	CmprOperator getCmprOperator();
	LogicOperator getLogicOperator();
};

#endif