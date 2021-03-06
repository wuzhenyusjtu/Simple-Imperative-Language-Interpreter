-------Overall Design of the Interpreter
1. Abstact Syntax Tree Representation (C++)
class SyntaxNode{
private:
SyntaxNode* child1;
SyntaxNode* child2;
SyntaxNode* child3;
...
public:
void parse(); // Generate a syntax tree through parsing
void print(); // Printing "pretty" code with the appropriate indentation
void execute(); // For Statement Node, Having Side Effects
void evaluate(); // For Expression Node, No Side Effects
}

2. Token
// Every token in the scanner's token stream has a token type
enum TokenType {TNONE, KEYWORD, PUNCTUATION, ARITHOPERATOR, CMPROPERATOR, LOGICOPERATOR, ASSIGNOPERATOR, IDENTIFIER, CONSTANT, MYEOF};
// Every keyword token has a keyword type
enum Keyword {KNONE, PROGRAM, BEGIN, END, INT, INPUT, OUTPUT, IF, THEN, ELSE, ENDIF, DO, WHILE, ENDDO, CASE, OF};
// Every punctuation token has a punctuation type
enum Punctuation {PNONE, SEMICOLON, COMMA, OPENPARENTHESIS, CLOSEPARENTHESIS, OPENBRACKET, CLOSEBRACKET, COLON, BAR};
// Every arithmetic operator token has a arithmetic operator type 
enum ArithOperator {ANONE, PLUSSIGN, MINUSSIGN, MULTSIGN};
// Every compare operator token has a compare operator type 
enum CmprOperator {CNONE, INEQUAL, EQUAL, LESS, LESSEQUAL, GREATER, GREATEREQUAL};
// Every logic operator token has a logic operator type 
enum LogicOperator {LNONE, NOT, AND, OR};

3. Scanner
// The scanner read token for the parser and read value for the input identifier in the executor or evaluator
class Scanner : public CoreLanguageMap
{
public:
	void nextToken(); // In the token stream, move forward to next token
	void prevToken(); // In the token stream, move backward to previous token
	Token currentToken(); // In the token stream, get the current token
	int getNextValue(); // In the value stream, get next value
}

4. Core Language Map
// Provides mappings from literals to enum types
class CoreLanguageMap
{
protected:
	map<string, Keyword> keywordMap;
	map<string, Punctuation> punctMap;
	map<string, ArithOperator> arithOprMap;
	map<string, CmprOperator> cmprOprMap;
	map<string, LogicOperator> logicOprMap;
}


------Testing of My Interpreter
I have passed all the weak tests provides.
Also, I have written a bash file to better test my interpreter.
bash:$ sh test.sh 
