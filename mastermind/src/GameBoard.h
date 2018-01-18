#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

#include "MasterMindException.h"
#include "CodePeg.h"
#include "KeyPeg.h"

using namespace std;

class CGameBoard
{
protected:
	unsigned int nCodeLength;
	unsigned int nColourNum;

	vector<CCodePeg>	vSecretCode;
	vector<CCodePeg>	vCurCode;
	vector<CKeyPeg>		vCurKey;

	bool	setVectorData(string sCodeStr, vector<CCodePeg> &vPegs);
	void	getCurKey();
public:
	CGameBoard(unsigned int nCodeLen, unsigned int nColNum);
	~CGameBoard();

	bool	setSecret(string sCodeStr);
	bool	processCurCode(string sCodeStr);

	string	getKeyPrintable();
	bool	chckKey();
};

#endif /*GAMEBOARD_H*/
