#pragma once

#include <iostream>
#include <string>
#include <map>
#include "global.h"
#include <cstdlib>


class IdentifierMap
{
private:
	std::map <std::string, int> identifierMap;
public:
	IdentifierMap();
	~IdentifierMap();
	int getValue(std::string key);
	void setValue(std::string key, int value);
	void insertKey(std::string key);
};

