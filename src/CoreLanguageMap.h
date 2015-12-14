#pragma once
#ifndef CORELANGUAGEMAP_H
#define CORELANGUAGEMAP_H

#include <map>
#include "Token.h"
#include <cstdlib>

class CoreLanguageMap
{
protected:
	map<string, Keyword> keywordMap;
	map<string, Punctuation> punctMap;
	map<string, ArithOperator> arithOprMap;
	map<string, CmprOperator> cmprOprMap;
	map<string, LogicOperator> logicOprMap;
public:
	CoreLanguageMap();
	~CoreLanguageMap();
	map<string, Keyword>& getKeywordMap();
	map<string, Punctuation>& getPunctMap();
	map<string, ArithOperator>& getArithOprMap();
	map<string, CmprOperator>& getCmprOprMap();
	map<string, LogicOperator> getLogicOprMap();
};
#endif

