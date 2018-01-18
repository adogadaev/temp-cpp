#include "Peg.h"

CPeg::CPeg(unsigned int nCol)
{
	if (nCol != RED && nCol != GREEN && nCol != CYAN &&
		nCol != YELLOW && nCol != MAGENTA && nCol != ORANGE &&
		nCol != BLACK && nCol != WHITE)
		throw MasterMindException("Unsupported peg colour id.");
	this->nColour = nCol;
}

CPeg::CPeg(const char cCol)
{		
	switch (cCol)
	{
	case 'r':
		this->nColour = RED;
		break;
	case 'g':
		this->nColour = GREEN;
		break;
	case 'c':
		this->nColour = CYAN;
		break;
	case 'y':
		this->nColour = YELLOW;
		break;
	case 'm':
		this->nColour = MAGENTA;
		break;
	case 'o':
		this->nColour = ORANGE;
		break;
	case 'b':
		this->nColour = BLACK;
		break;
	case 'w':
		this->nColour = WHITE;
		break;
	default:
		throw MasterMindException("Unsupported peg colour.");
	}
}

CPeg::CPeg()
{
	this->nColour = NOT_SPECIFIED;
}


CPeg::~CPeg()
{
}

unsigned int CPeg::getColour()
{
	return this->nColour;
}
