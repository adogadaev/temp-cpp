#include "KeyPeg.h"

CKeyPeg::CKeyPeg(unsigned int nCol) : CPeg(nCol)
{
	if (nCol != BLACK && nCol != WHITE)
		throw MasterMindException("Key pegs can only be black or white.");
}

CKeyPeg::CKeyPeg() : CPeg()
{
}

CKeyPeg::~CKeyPeg()
{
}

void CKeyPeg::setColour(unsigned int nCol)
{
	if (nCol != BLACK && nCol != WHITE)
		throw MasterMindException("Key pegs can only be black or white.");
	this->nColour = nCol;
}
