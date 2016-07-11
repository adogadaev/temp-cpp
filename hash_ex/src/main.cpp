#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <iterator>

#include "cCmdLineParser.h"
#include "cWordCounter.h"

using namespace std;

static void show_usage(std::string name)
{
    cerr << "Usage: " << name << " [OPTION] [-i INPUT -o OUTPUT]" << endl
              << "Options:" << endl
              << "\t-h,--help\t\tShow this help message" << endl
              << endl;
}

int main (int argc, char* argv[])
{
	cCmdLineParser cInpParser(argc, argv);
	cWordCounter cCounter;
	ifstream fInput;
	ofstream fOutput;

	try
	{
		const string &sInputFile = cInpParser.getOption("-i");
		const string &sOutputFile = cInpParser.getOption("-o");
		if (cInpParser.checkOption("-h") || cInpParser.checkOption("--help") || sInputFile.empty() || sOutputFile.empty())
		{
			show_usage(argv[0]);
			return 1;
		}

		fInput.open(sInputFile, ifstream::in);
		if (!fInput.is_open())
		{
			cerr << "Cannot read from the input file " << sInputFile << endl;
			return 1;
		}
		string line;
		while (getline(fInput, line))
			cCounter.countWords(line);
		fInput.close();

		unordered_map<string,unsigned int> mpRes = cCounter.getResult();
		fOutput.open(sOutputFile, ios::out);
		if (!fOutput.is_open())
		{
			cerr << "Cannot write to the output file " << sOutputFile << endl;
			return 1;
		}

		for (auto& x: mpRes)
		{
			fOutput << x.second << ": " << x.first << endl;
		}
		fOutput.close();

		cout << "The data was written to the file " << sOutputFile << endl;
	}
	catch (...)
	{
		throw;
	}

	return 0;
}
