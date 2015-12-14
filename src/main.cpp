#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <map>
#include "Scanner.h"
#include "Prog.h"
#include "global.h"

using namespace std;

int main(int argc, char * argv[]) {
	string codeInfile = argv[1];
	string dataInfile;
	string outfile;
	if (argc == 3)
	{
		outfile = argv[2];
	}
	else if (argc == 4)
	{
		dataInfile = argv[2];
		outfile = argv[3];
	}
	else {
		throw runtime_error("Expected 2 or 3 parameters, 1st paramter for code input file,\
			2nd paremeter for data input file (optional), 3rd paramter for output file");
	}

	ifstream in;
	in.open(codeInfile.c_str(), ifstream::in);
	string line;
	vector<string> codeVec;
	while (getline(in, line))
	{
		line += '\n';
		codeVec.push_back(line);
	}
	in.close();

	if (argc == 3)
	{
		scanner = new Scanner(codeVec);
	}

	if (argc == 4)
	{
		in.open(dataInfile.c_str(), ifstream::in);
		vector<string> dataVec;
		while (getline(in, line))
		{
			line += '\n';
			dataVec.push_back(line);
		}
		in.close();
		scanner = new Scanner(codeVec, dataVec);
	}
	
	out.open(outfile.c_str(), ofstream::out);
	Prog *prog = new Prog();
	prog->parse();
	prog->print();
	prog->execute();
	out.close();
	return 0;
}