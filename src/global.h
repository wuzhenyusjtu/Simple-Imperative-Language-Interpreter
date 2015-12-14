#pragma once
#ifndef GLOBAL_H
#define GLOBAL_H
#include <fstream>
#include <map>
#include <string>
#include <iostream>

#define UNINITIALIZED -1000000
#define GUARD -1000000

class Scanner;
class IdentifierMap;

extern Scanner *scanner;
extern std::ofstream out;
extern IdentifierMap *identifierMap;
#endif