#ifndef KEYPEG_H
#define KEYPEG_H

#include "MasterMindException.h"
#include "Peg.h"

using namespace std;

class CKeyPeg :	public CPeg
{
public:
	CKeyPeg(unsigned int nCol);
	CKeyPeg();
	~CKeyPeg();

	void setColour(unsigned int nCol);
};

#endif /*KEYPEG_H*/
