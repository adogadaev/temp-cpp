/*
 * cCmdLineParser.cpp
 *
 *  Created on: Jul 10, 2016
 *      Author: dan
 */

#include "cCmdLineParser.h"

#include <algorithm>

const std::string cCmdLineParser::sEmpty = "";

cCmdLineParser::cCmdLineParser(int &argc, char **argv) {
	// TODO Auto-generated constructor stub
	for (int i = 0; i < argc; i++)
		this->vOptions.push_back(std::string(argv[i]));
}

cCmdLineParser::~cCmdLineParser() {
	// TODO Auto-generated destructor stub
}

bool cCmdLineParser::checkOption(const std::string &sOpt) const
{
	return std::find(this->vOptions.begin(), this->vOptions.end(), sOpt) != this->vOptions.end();
}

const std::string& cCmdLineParser::getOption(const std::string &sOpt) const
{
	std::vector<std::string>::const_iterator itr;

	itr = std::find(this->vOptions.begin(), this->vOptions.end(), sOpt);
	if (itr != this->vOptions.end() && ++itr != this->vOptions.end())
		return *itr;
	return sEmpty;
}

