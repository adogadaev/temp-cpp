#include "GameBoard.h"


CGameBoard::CGameBoard(unsigned int nCodeLen, unsigned int nColNum)
{
	if (nColNum != 8)
		throw MasterMindException("The number of colours should be 8.");

	this->nCodeLength = nCodeLen;
	this->nColourNum = nColNum;
}


CGameBoard::~CGameBoard()
{
}

bool CGameBoard::setSecret(string sCodeStr)
{
	return setVectorData(sCodeStr, this->vSecretCode);
}

bool CGameBoard::processCurCode(string sCodeStr)
{
	if (setVectorData(sCodeStr, this->vCurCode))
	{
		getCurKey();
		return true;
	}
	return false;
}

bool CGameBoard::setVectorData(string sCodeStr, vector<CCodePeg> &vPegs)
{
	sCodeStr.erase(remove_if(sCodeStr.begin(), sCodeStr.end(), ::isspace), sCodeStr.end());
	transform(sCodeStr.begin(), sCodeStr.end(), sCodeStr.begin(), ::tolower);

	if (sCodeStr.length() != this->nCodeLength)
		throw MasterMindException("Invalid length of the code sequence.");

	if (vPegs.empty() == false)
		vPegs.erase(vPegs.begin(), vPegs.end());

	for (unsigned int i = 0; i < this->nCodeLength; i++)
		vPegs.push_back(CCodePeg(sCodeStr[i]));

	return true;
}

void CGameBoard::getCurKey()
{
	if (vCurCode.size() != vSecretCode.size() || vCurCode.size() != nCodeLength || vSecretCode.size() != nCodeLength)
		throw MasterMindException("The length of the code arrays provided for key calculation do not match expected value.");

	if (vCurKey.empty() == false)
		vCurKey.erase(vCurKey.begin(), vCurKey.end());

	vCurKey.resize(nCodeLength, CKeyPeg());

	unsigned int nCorrectPegNum = 0;
	unsigned int nWrongPosPegNum = 0;
	vector<unsigned int> vSecrColApperances(this->nColourNum, 0);
	vector<unsigned int> vCurColApperances(this->nColourNum, 0);
	for (unsigned int i = 0; i < this->nCodeLength; i++)
	{
		if (vCurCode[i] == vSecretCode[i])
			nCorrectPegNum++;

		vCurColApperances[vCurCode[i].getColour() - 1]++;
		vSecrColApperances[vSecretCode[i].getColour() - 1]++;
	}
	unsigned int nMinSum = 0;
	for (unsigned int i = 0; i < this->nColourNum; i++)
		nMinSum += min(vCurColApperances[i], vSecrColApperances[i]);
	nWrongPosPegNum = nMinSum - nCorrectPegNum;
	if ((nCorrectPegNum + nWrongPosPegNum) > nCodeLength || ((int)nMinSum - (int)nCorrectPegNum) < 0)
		throw MasterMindException("The algorithm for key calculation failed. If you see this, tell Anton that he screwed up and has to make a bug fix.");

	for (unsigned int i = 0; i < nCorrectPegNum; i++)
		vCurKey[i].setColour(BLACK);
	for (unsigned int i = nCorrectPegNum; i < (nCorrectPegNum + nWrongPosPegNum); i++)
		vCurKey[i].setColour(WHITE);
}

string	CGameBoard::getKeyPrintable()
{
	if (vCurKey.size() != nCodeLength)
		throw MasterMindException("The key length is invalid.");

	string sKey;
	for (unsigned int i = 0; i < vCurKey.size(); i++)
	{
		if (vCurKey[i].getColour() == NOT_SPECIFIED)
			sKey.push_back('_');
		else if (vCurKey[i].getColour() == BLACK)
			sKey.push_back('v');
		else if (vCurKey[i].getColour() == WHITE)
			sKey.push_back('o');
		else
			throw MasterMindException("Unsupported colour of a key peg.");
	}

	return sKey;
}

bool CGameBoard::chckKey()
{
	if (vCurKey.size() != nCodeLength)
		throw MasterMindException("The key length is invalid.");
	for (unsigned int i = 0; i < vCurKey.size(); i++)
		if (vCurKey[i].getColour() != BLACK)
			return false;
	return true;
}
