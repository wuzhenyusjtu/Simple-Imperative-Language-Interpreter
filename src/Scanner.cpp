#include "Scanner.h"
#include "Token.h"
#include <iostream>
#include "global.h"

Scanner::Scanner(vector<string> codeVec, vector<string> dataVec) : CoreLanguageMap()
{
	tokenCount = -1;
	valueCount = -1;
	for (vector<string>::iterator it = codeVec.begin(); it != codeVec.end(); it++)
	{
		getTokensFromString(*it);
	}
	tokenVec.push_back(Token("EOF", MYEOF));

	for (vector<string>::iterator it = dataVec.begin(); it < dataVec.end(); it++)
	{
		getValueFromString(*it);
	}
	valueVec.push_back(GUARD);
}

Scanner::Scanner(vector<string> codeVec) : CoreLanguageMap()
{
	tokenCount = -1;
	valueCount = -1;
	for (vector<string>::iterator it = codeVec.begin(); it != codeVec.end(); it++)
	{
		getTokensFromString(*it);
	}
	tokenVec.push_back(Token("EOF", MYEOF));
}

void Scanner::test() {
	for (int i = 0; i < tokenVec.size(); i++)
	{
		out << tokenVec[i].getLiteral();

		switch (tokenVec[i].getType())
		{
		case 1: out << '\t' << "KEYWORD"; break;
		case 2: out << '\t' << "PUNCTUATION"; break;
		case 3: out << '\t' << "ARITHOPERATOR"; break;
		case 4: out << '\t' << "CMPROPERATOR"; break;
		case 5: out << '\t' << "LOGICOPERATOR"; break;
		case 6: out << '\t' << "ASSIGNOPERATOR"; break;
		case 7: out << '\t' << "IDENTIFIER"; break;
		case 8: out << '\t' << "CONSTANT"; break;
		case 9: out << '\t' << "MYEOF"; break;
		default:{ cout << "Bug Identified: Token Type Assigning Failed" << endl; exit(0); }
			break;
		}

		switch (tokenVec[i].getKeyword())
		{
		case 0:break;
		case 1:	out << '\t' << "PROGRAM"; break;
		case 2: out << '\t' << "BEGIN"; break;
		case 3: out << '\t' << "END"; break;
		case 4: out << '\t' << "INT"; break;
		case 5: out << '\t' << "INPUT"; break;
		case 6: out << '\t' << "OUTPUT"; break;
		case 7: out << '\t' << "IF"; break;
		case 8: out << '\t' << "THEN"; break;
		case 9: out << '\t' << "ELSE"; break;
		case 10: out << '\t' << "ENDIF"; break;
		case 11: out << '\t' << "DO"; break;
		case 12: out << '\t' << "WHILE"; break;
		case 13: out << '\t' << "ENDDO"; break;
		case 14: out << '\t' << "CASE"; break;
		case 15: out << '\t' << "OF"; break;
		default:{ cout << "Bug Identified: Keyword Assigning Failed" << endl; exit(0); }
			break;
		}

		switch (tokenVec[i].getArithOperator())
		{
		case 0:break;
		case 1:out << '\t' << "PLUSSIGN"; break;
		case 2:out << '\t' << "MINUSSIGN";break;
		case 3:out << '\t' << "MULTSIGN"; break;
		default:{ cout << "Bug Identified: Arithmetic Operator Assigning Failed"<< endl; exit(0); }
			break;
		}

		switch (tokenVec[i].getCmprOperator())
		{
		case 0:break;
		case 1:out << '\t' << "INEQUAL"; break;
		case 2:out << '\t' << "EQUAL"; break;
		case 3:out << '\t' << "LESS"; break;
		case 4:out << '\t' << "LESSEQUAL"; break;
		case 5:out << '\t' << "GREATER"; break;
		case 6:out << '\t' << "GREATEREQUAL"; break;
		default:{ cout << "Bug Identified: Compare Operator Assigning Failed"<< endl; exit(0); }
			break;
		}

		//enum LogicOperator { LNONE, NOT, AND, OR }
		switch (tokenVec[i].getLogicOperator())
		{
		case 0:break;
		case 1:out << '\t' << "NOT"; break;
		case 2:out << '\t' << "AND"; break;
		case 3:out << '\t' << "OR"; break;
		default:{ cout << "Bug Identified: Logic Operator Assigning Failed"<< endl; exit(0); }
			break;
		}

		switch (tokenVec[i].getPunctuation())
		{
		case 0:break;
		case 1: out << '\t' << "SEMICOLON"; break;
		case 2: out << '\t' << "COMMA"; break;
		case 3: out << '\t' << "OPENPARENTHESIS"; break;
		case 4: out << '\t' << "CLOSEPARENTHESIS"; break;
		case 5: out << '\t' << "OPENBRACKET"; break;
		case 6: out << '\t' << "CLOSEBRACKET"; break;
		case 7: out << '\t' << "COLON"; break;
		case 8: out << '\t' << "BAR"; break;
		default:{ cout << "Bug Identified: Punctuation Assigning Failed"<< endl; exit(0); }
			break;
		}
		out << endl;
	}
	for(int i = 0; i < valueVec.size(); ++i)
	{
		out << valueVec[i] << '\t' << "DATA" << endl;
	}
}

int Scanner::getNextValue()
{
	valueCount++;
	if (valueCount < (int)valueVec.size())
	{
		return valueVec[valueCount];
	}
	else {
		cout << "ERROR: No Matching Value for Current Input Idenfitier" << endl;
		exit(0);
	}
}

void Scanner::nextToken()
{
	tokenCount++;
	//cout << tokenVec[tokenCount].getLiteral() << tokenVec[tokenCount].getType() << endl;
	if (tokenCount >= (int)tokenVec.size()){
		cout << "ERROR: No Token Left in the Stream" << endl;
		exit(0);
	}
}

void Scanner::prevToken()
{
	tokenCount--;
}


Token Scanner::currentToken()
{
	if (tokenCount < (int)tokenVec.size())
	{
		return tokenVec[tokenCount];
	}
	else {
		cout << "ERROR: No Token Left in the Stream" << endl;
		exit(0);
	}
}

bool Scanner::isDigit(char c)
{
	return c >= '0' && c <= '9';
}

bool Scanner::isLetter(char c)
{
	return (c >= 'a'&& c <= 'z') || (c >= 'A'&&c <= 'Z');
}

bool Scanner::isPunctuation(char c)
{
	return c == ';' || c == ',' || c == '(' || c == ')' || c == '[' || c == ']' || c == '|' || c == ':' || c == '|';
}

bool Scanner::isArithOperator(char c)
{
	return c == '+' || c == '-' || c == '*';
}

bool Scanner::isEqualSign(char c)
{
	return c == '=';
}

bool Scanner::isGreaterLessSign(char c)
{
	return c == '>' || c == '<';
}

bool Scanner::isExclamation(char c)
{
	return c == '!';
}

bool Scanner::isColon(char c)
{
	return c == ':';
}

bool Scanner::isValidChar(char c)
{
	return isDigit(c) || isLetter(c) || isPunctuation(c) || isOperatorComponent(c);
}

bool Scanner::isOperatorComponent(char c)
{
	return isArithOperator(c) || isGreaterLessSign(c) || isEqualSign(c) || isExclamation(c) || isColon(c);
}

void Scanner::getTokensFromString(string s)
{
	int i = 0;
	while (i < s.size())
	{
		if (isPunctuation(s[i]) && s[i] != ':')
		{
			string temp = string(1, s[i]);
			tokenVec.push_back(Token(temp, PUNCTUATION, punctMap.find(temp)->second));
			i++;
		}
		else if (isArithOperator(s[i]))
		{
			string temp = string(1, s[i]);
			tokenVec.push_back(Token(temp, ARITHOPERATOR, arithOprMap.find(temp)->second));
			i++;
		}
		else if (isLetter(s[i]))
		{
			string temp = string(1, s[i]);
			while (isLetter(s[i + 1]) || isDigit(s[i + 1]))
			{
				i++;
				temp += s[i];
			}
			if (keywordMap.find(temp) != keywordMap.end())
			{
				Token t = Token(temp, KEYWORD, keywordMap.find(temp)->second);
				tokenVec.push_back(Token(temp, KEYWORD, keywordMap.find(temp)->second));
			}
			else if (logicOprMap.find(temp) != logicOprMap.end())
			{
				Token t = Token(temp, LOGICOPERATOR, logicOprMap.find(temp)->second);
				tokenVec.push_back(Token(temp, LOGICOPERATOR, logicOprMap.find(temp)->second));
			}
			else {
				Token t = Token(temp, IDENTIFIER);
				tokenVec.push_back(Token(temp, IDENTIFIER));
			}
			i++;
		}
		else if (isColon(s[i]))
		{
			string temp = string(1, s[i]);
			if (isEqualSign(s[++i]))
			{
				temp += s[i];
				tokenVec.push_back(Token(temp, ASSIGNOPERATOR));
			}
			else {
				i--;
				tokenVec.push_back(Token(temp, PUNCTUATION, COLON));
			}
			i++;
		}
		else if (isDigit(s[i]))
		{
			string temp = string(1, s[i]);
			while (isDigit(s[++i]))
			{
				temp += s[i];
			}
			tokenVec.push_back(Token(temp, CONSTANT));
		}
		else if (isEqualSign(s[i]))
		{
			string temp = string(1, s[i]);
			tokenVec.push_back(Token(temp, CMPROPERATOR, cmprOprMap.find(temp)->second));
			i++;
		}
		else if (isExclamation(s[i]))
		{
			string temp = string(1, s[i]);
			if (isEqualSign(s[i + 1]))
			{
				temp += s[++i];
				tokenVec.push_back(Token(temp, CMPROPERATOR, cmprOprMap.find(temp)->second));
				i++;
			}
			else
			{
				tokenVec.push_back(Token(temp, LOGICOPERATOR, logicOprMap.find(temp)->second));
				i++;
			}
		}
		else if (isGreaterLessSign(s[i]))
		{
			string temp = string(1, s[i]);
			if (isEqualSign(s[i + 1]))
			{
				temp += s[++i];
				tokenVec.push_back(Token(temp, CMPROPERATOR, cmprOprMap.find(temp)->second));
				i++;
			}
			else
			{
				tokenVec.push_back(Token(temp, CMPROPERATOR, cmprOprMap.find(temp)->second));
				i++;
			}
		}
		else if (isspace(s[i]))
		{
			i++;
		}
		else {
			cout << "ERROR: Invalid Character Input!" << endl;
			exit(0);
		}
	}
}

void Scanner::getValueFromString(string s)
{
	int value = 0;
	bool isNegative = false;
	for (int i = 0; i < s.size(); i++)
	{
		if (!isspace(s[i]))
		{
			if (isdigit(s[i]))
			{
				value *= 10;
				value += s[i] - '0';
			}
			else if(s[i]=='-')
			{
				if(isNegative == false) isNegative = true;
				else{ cout << "ERROR: Consecutive Negative Signs Encountered!" << endl; exit(0); }
			}
			else{ cout << "ERROR: Expected Digit or Space" << endl; exit(0); }
		}
		else
		{
			if (value != 0)
			{
				if(isNegative) valueVec.push_back(-value);
				else valueVec.push_back(value);
				isNegative = false;
				value = 0;
			}
		}
	}
}