#include "CoreLanguageMap.h"

CoreLanguageMap::CoreLanguageMap()
{
	keywordMap.insert(pair<string, Keyword>("program", PROGRAM));
	keywordMap.insert(pair<string, Keyword>("begin", BEGIN));
	keywordMap.insert(pair<string, Keyword>("end", END));
	keywordMap.insert(pair<string, Keyword>("int", INT));
	keywordMap.insert(pair<string, Keyword>("input", INPUT));
	keywordMap.insert(pair<string, Keyword>("output", OUTPUT));
	keywordMap.insert(pair<string, Keyword>("if", IF));
	keywordMap.insert(pair<string, Keyword>("then", THEN));
	keywordMap.insert(pair<string, Keyword>("else", ELSE));
	keywordMap.insert(pair<string, Keyword>("endif", ENDIF));
	keywordMap.insert(pair<string, Keyword>("do", DO));
	keywordMap.insert(pair<string, Keyword>("while", WHILE));
	keywordMap.insert(pair<string, Keyword>("enddo", ENDDO));
	keywordMap.insert(pair<string, Keyword>("case", CASE));
	keywordMap.insert(pair<string, Keyword>("of", OF));
	punctMap.insert(pair<string, Punctuation>(";", SEMICOLON));
	punctMap.insert(pair<string, Punctuation>(",", COMMA));
	punctMap.insert(pair<string, Punctuation>("(", OPENPARENTHESIS));
	punctMap.insert(pair<string, Punctuation>(")", CLOSEPARENTHESIS));
	punctMap.insert(pair<string, Punctuation>("[", OPENBRACKET));
	punctMap.insert(pair<string, Punctuation>("]", CLOSEBRACKET));
	punctMap.insert(pair<string, Punctuation>("|", BAR));
	punctMap.insert(pair<string, Punctuation>(":", COLON));
	//enum LogicOperator { LNONE, NOT, AND, OR };
	arithOprMap.insert(pair<string, ArithOperator>("+", PLUSSIGN));
	arithOprMap.insert(pair<string, ArithOperator>("-", MINUSSIGN));
	arithOprMap.insert(pair<string, ArithOperator>("*", MULTSIGN));
	cmprOprMap.insert(pair<string, CmprOperator>("!=", INEQUAL));
	cmprOprMap.insert(pair<string, CmprOperator>("=", EQUAL));
	cmprOprMap.insert(pair<string, CmprOperator>("<", LESS));
	cmprOprMap.insert(pair<string, CmprOperator>("<=", LESSEQUAL));
	cmprOprMap.insert(pair<string, CmprOperator>(">", GREATER));
	cmprOprMap.insert(pair<string, CmprOperator>(">=", GREATEREQUAL));
	logicOprMap.insert(pair<string, LogicOperator>("!", NOT));
	logicOprMap.insert(pair<string, LogicOperator>("AND", AND));
	logicOprMap.insert(pair<string, LogicOperator>("OR", OR));
}


CoreLanguageMap::~CoreLanguageMap()
{
}

map<string, Keyword>& CoreLanguageMap::getKeywordMap() { return keywordMap; }
map<string, Punctuation>& CoreLanguageMap::getPunctMap() { return punctMap; }
map<string, ArithOperator>& CoreLanguageMap::getArithOprMap() { return arithOprMap; }
map<string, CmprOperator>& CoreLanguageMap::getCmprOprMap() { return cmprOprMap; }
map<string, LogicOperator> CoreLanguageMap::getLogicOprMap() { return logicOprMap; }