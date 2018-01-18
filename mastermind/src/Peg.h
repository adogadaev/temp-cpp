#ifndef PEG_H
#define PEG_H

#include "MasterMindException.h"

enum PegColour : unsigned int { NOT_SPECIFIED, BLACK, WHITE, RED, GREEN, CYAN, YELLOW, MAGENTA, ORANGE };

using namespace std;

class CPeg
{
protected:
	unsigned int nColour;
public:
	CPeg(unsigned int nCol);
	CPeg(const char cCol);
	CPeg();
	~CPeg();

	unsigned int getColour();

	inline bool operator==(const CPeg& rhs) const
	{
		return (rhs.nColour == nColour);
	}
};

#endif /*PEG_H*/
