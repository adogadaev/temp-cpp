#include <iostream>
#include <exception>
#include <vector>
#include <string>

#ifdef WIN32
#include <windows.h>
#else
#include <string.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#endif

#include "GameBoard.h"
#include "KeyPeg.h"
#include "CodePeg.h"

using namespace std;

void SetStdinEcho(bool enable = true);
bool is_number(const string&);
void printHelp(unsigned int);

int main(int argc, char** argv) {
	try {
		unsigned int nColourNum = 8;
		unsigned int nCodeLength = 8;
		unsigned int nStepNum = 10;

		bool hideInput = true;

		if (argc == 1)
			cout << "For help use command line options '--help', '-?' or '/?'." << endl;

		if (argc == 2 && (!strcmp(argv[1], "--help") || !strcmp(argv[1], "-?") || !strcmp(argv[1], "/?")))
		{
			printHelp(nColourNum);
			return 0;
		}

		for (unsigned int i = 1; i < argc; i++)
		{
			if (!strcmp(argv[i], "-clen") && (i + 1) != argc)
			{
				string sCodeLength(argv[i + 1]);
				if (is_number(sCodeLength))
				{
					nCodeLength = stoi(sCodeLength);
					i++;
				}
				else
				{
					printHelp(nColourNum);
					return 0;
				}
			}
			else if (!strcmp(argv[i], "-steps") && (i + 1) != argc)
			{
				string sStepNum(argv[i + 1]);
				if (is_number(sStepNum))
				{
					nStepNum = stoi(sStepNum);
					i++;
				}
				else
				{
					printHelp(nColourNum);
					return 0;
				}
			}
			else if (!strcmp(argv[i], "-opengame"))
			{
				hideInput = false;
			}
			else
			{
				printHelp(nColourNum);
				return 0;
			}
		}

		CGameBoard cBoard(nCodeLength, nColourNum);

		cout << "#################################" << endl;
		cout << "#\tGame settings\t\t#" << endl;
		cout << "# Code length:\t\t" << nCodeLength << "\t#" << endl;
		cout << "# Maximum steps:\t" << nStepNum << "\t#" << endl;
		cout << "# Maximum colours:\t" << nColourNum << "\t#" << endl;
		cout << "#################################" << endl;


		cout << "Input secret code: ";

		string sSecretCode;
		SetStdinEcho(!hideInput);
		getline(cin, sSecretCode);
		SetStdinEcho();
		if (hideInput)
			cout << endl;
		cBoard.setSecret(sSecretCode);

		for (unsigned int i = 0; i < nStepNum; i++)
		{
			cout << "Round\t" << (i + 1) << "/" << nStepNum << ":\t";

			string sCurSeqData;
			getline(cin, sCurSeqData);
			cBoard.processCurCode(sCurSeqData);

			cout << "Key\t" << (i + 1) << "/" << nStepNum << ":\t" << cBoard.getKeyPrintable() << endl;

			if (cBoard.chckKey())
			{
				cout << "Congratulations! The answer is correct." << endl;
				return 0;
			}
		}

		cout << "Game Over!" << endl;

	}
	catch (exception& e) {
		cout << "An exception occurred: " << e.what() << endl;
	}

	return 0;
}


void SetStdinEcho(bool enable)
{
#ifdef WIN32
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(hStdin, &mode);

	if (!enable)
		mode &= ~ENABLE_ECHO_INPUT;
	else
		mode |= ENABLE_ECHO_INPUT;

	SetConsoleMode(hStdin, mode);

#else
	struct termios tty;
	tcgetattr(STDIN_FILENO, &tty);
	if (!enable)
		tty.c_lflag &= ~ECHO;
	else
		tty.c_lflag |= ECHO;

	(void)tcsetattr(STDIN_FILENO, TCSANOW, &tty);
#endif
}

bool is_number(const std::string& s)
{
	return !s.empty() && find_if(s.begin(), s.end(), [](char c) { return !isdigit(c); }) == s.end();
}

void printHelp(unsigned int nColourNum)
{
	cout << "Usage: program [-opengame] [-clen number] [-steps number]" << endl;
	cout << "With the option '-opengame' enabled the game doesn't hide secret code sequence." << endl;
	cout << "The option '-clen' provides oportunity to change a code length (set to 8 by default)." << endl;
	cout << "The option '-steps' sets up the maximum amount of available attempts to guess the code sequence (set to 10 by default)." << endl;
	cout << endl;

	cout << "The player is allowed to use up to " << nColourNum << " colours." << endl;
	cout << "The list of colours and their representation in the game:" << endl;
	cout << "\t1) Black is represented by letter 'b' or 'B'" << endl;
	cout << "\t2) White is represented by letter 'w' or 'W'" << endl;
	cout << "\t3) Red is represented by letter 'r' or 'R'" << endl;
	cout << "\t4) Green is represented by letter 'g' or 'G'" << endl;
	cout << "\t5) Cyan is represented by letter 'c' or 'C'" << endl;
	cout << "\t6) Yellow is represented by letter 'y' or 'Y'" << endl;
	cout << "\t7) Magenta is represented by letter 'm' or 'M'" << endl;
	cout << "\t8) Orange is represented by letter 'o' or 'O'" << endl << endl;

	cout << "Input is not case-sensitive and duplicate colours are allowed." << endl << endl;

	cout << "The key pegs are represented as follows:" << endl;
	cout << "\t1) The key peg 'v' indicates presence of a code peg of correct colour in the correct position" << endl;
	cout << "\t2) The key peg 'o' indicates presence of a code peg of correct colour in the wrong position" << endl;
}
