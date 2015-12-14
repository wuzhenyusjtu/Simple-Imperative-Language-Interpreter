#include "IdentifierMap.h"



IdentifierMap::IdentifierMap()
{
}


IdentifierMap::~IdentifierMap()
{
}

int IdentifierMap::getValue(std::string key) {
	std::map<std::string, int>::iterator it;
	it = identifierMap.find(key);
	if (it != identifierMap.end())
	{
		if (it->second == UNINITIALIZED)
		{
			std::cout << "ERROR: Identifier " + key + " Uninitialized" << std::endl; exit(0);
		}
		else return it->second;
	}
	else { std::cout << "ERROR: Identifier " + key + " Undeclared" << std::endl; exit(0); }
}

void IdentifierMap::setValue(std::string key, int value) {
	std::map<std::string, int>::iterator it;
	it = identifierMap.find(key);
	if (it != identifierMap.end())
	{
		identifierMap[key] = value;
	}
	else { std::cout << "ERROR: Identifier " + key + " Undeclared" << std::endl; exit(0); }
}

void IdentifierMap::insertKey(std::string key) {
	std::pair<std::map<std::string, int>::iterator, bool> ret = identifierMap.insert(std::make_pair(key, UNINITIALIZED));
	if (!ret.second)
	{
		std::cout << "ERROR: Identifier " + key + " Already Declared" << std::endl; exit(0);
	}
}