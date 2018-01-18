#ifndef CODEPEG_H
#define CODEPEG_H

#include "Peg.h"

class CCodePeg : public CPeg
{
public:
	CCodePeg(unsigned int nCol);
	CCodePeg(char cCol);
	CCodePeg();
	~CCodePeg();
};

#endif /*CODEPEG_H*/