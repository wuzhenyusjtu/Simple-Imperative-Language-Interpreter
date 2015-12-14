#pragma once
#ifndef SCANNER_H
#define SCANNER_H

#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>
#include <stdexcept>
#include "CoreLanguageMap.h"
#include "global.h"

using namespace std;

class Token;

class Scanner : public CoreLanguageMap
{
public:
	Scanner(vector<string> codeVec, vector<string> dataVec);
	Scanner(vector<string> codeVec);
	void nextToken();
	void prevToken();
	Token currentToken();
	int getNextValue();
	void test();
private:
	vector<Token> tokenVec;
	vector<int> valueVec;
	int tokenCount;
	int valueCount;
	bool isDigit(char c);
	bool isLetter(char c);
	bool isPunctuation(char c);
	bool isArithOperator(char c);
	bool isValidChar(char c);
	bool isEqualSign(char c);
	bool isExclamation(char c);
	bool isGreaterLessSign(char c);
	bool isColon(char c);
	bool isOperatorComponent(char c);
	void getTokensFromString(string s);
	void getValueFromString(string s);
};

#endif