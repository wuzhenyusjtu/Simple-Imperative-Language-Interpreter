#include "Token.h"



Token::Token(string literal, TokenType tokenType)
{
	this->literal = literal;
	this->tokenType = tokenType;
	this->keyword = KNONE;
	this->punctuation = PNONE;
	this->arithOperator = ANONE;
	this->cmprOperator = CNONE;
	this->logicOperator = LNONE;
}

Token::Token(string literal, TokenType tokenType, Keyword keyword)
{
	this->literal = literal;
	this->tokenType = tokenType;
	this->keyword = keyword;
	this->punctuation = PNONE;
	this->arithOperator = ANONE;
	this->cmprOperator = CNONE;
	this->logicOperator = LNONE;
}

Token::Token(string literal, TokenType tokenType, Punctuation punctuation)
{
	this->literal = literal;
	this->tokenType = tokenType;
	this->punctuation = punctuation;
	this->keyword = KNONE;
	this->arithOperator = ANONE;
	this->cmprOperator = CNONE;
	this->logicOperator = LNONE;
}

Token::Token(string literal, TokenType tokenType, ArithOperator arithOperator)
{
	this->literal = literal;
	this->tokenType = tokenType;
	this->arithOperator = arithOperator;
	this->keyword = KNONE;
	this->punctuation = PNONE;
	this->cmprOperator = CNONE;
	this->logicOperator = LNONE;
}

Token::Token(string literal, TokenType tokenType, CmprOperator cmprOperator)
{
	this->literal = literal;
	this->tokenType = tokenType;
	this->cmprOperator = cmprOperator;
	this->keyword = KNONE;
	this->punctuation = PNONE;
	this->arithOperator = ANONE;
	this->logicOperator = LNONE;
}

Token::Token(string literal, TokenType tokenType, LogicOperator logicOperator)
{
	this->literal = literal;
	this->tokenType = tokenType;;
	this->logicOperator = logicOperator;
	this->keyword = KNONE;
	this->punctuation = PNONE;
	this->arithOperator = ANONE;
	this->cmprOperator = CNONE;
}

string Token::getLiteral() { return literal; }
TokenType Token::getType() { return tokenType; }
Keyword Token::getKeyword() { return keyword; }
Punctuation Token::getPunctuation() { return punctuation; }
ArithOperator Token::getArithOperator() { return arithOperator; }
CmprOperator Token::getCmprOperator() { return cmprOperator; }
LogicOperator Token::getLogicOperator() { return logicOperator; }