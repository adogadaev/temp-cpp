/*
 * cWordCounter.cpp
 *
 *  Created on: Jul 11, 2016
 *      Author: dan
 */

#include "cWordCounter.h"

#include <algorithm>
#include <iterator>

cWordCounter::cWordCounter()
{
	// TODO Auto-generated constructor stub
}

cWordCounter::~cWordCounter()
{
	// TODO Auto-generated destructor stub
}

void cWordCounter::countWords(std::string &line)
{
	std::size_t prev = 0, pos;
	while ((pos = line.find_first_of(" ,./?<>|\"\\':;[]{}=-!@#$%^&*()_+`~1234567890\n\t", prev)) != std::string::npos)
	{
		if (pos > prev)
		{
			std::string word = line.substr(prev, pos-prev);
			std::transform(word.begin(), word.end(), word.begin(), ::tolower);
			this->mpHash[word]++;
		}
		prev = pos+1;
	}
	if (prev < line.length())
	{
		std::string word = line.substr(prev, std::string::npos);
		std::transform(word.begin(), word.end(), word.begin(), ::tolower);
		this->mpHash[word]++;
	}
}

std::unordered_map<std::string,unsigned int> cWordCounter::getResult()
{
	return this->mpHash;
}
