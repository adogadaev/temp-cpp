/*
 * cCmdLineParser.h
 *
 *  Created on: Jul 10, 2016
 *      Author: dan
 */

#ifndef CCMDLINEPARSER_H_
#define CCMDLINEPARSER_H_

#include <string>
#include <vector>

class cCmdLineParser {
public:
	cCmdLineParser(int &argc, char **argv);
	virtual ~cCmdLineParser();

	bool checkOption(const std::string &sOpt) const;
	const std::string& getOption(const std::string &sOpt) const;
private:
	std::vector<std::string> vOptions;
	static const std::string sEmpty;
};

#endif /* CCMDLINEPARSER_H_ */
