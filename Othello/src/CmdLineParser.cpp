#include "CmdLineParser.h"

#include <algorithm>

const std::string CmdLineParser::empty_ = "";

CmdLineParser::CmdLineParser(int& argc, char** argv) {
	for (int i = 0; i < argc; i++) {
		options_.push_back(std::string(argv[i]));
	}
}

bool CmdLineParser::checkOption(const std::string& option) const {
	return std::find(options_.begin(), options_.end(), option) != options_.end();
}

const std::string& CmdLineParser::getOption(const std::string& option) const {
	std::vector<std::string>::const_iterator itr;

	itr = std::find(options_.begin(), options_.end(), option);
	if (itr != options_.end() && ++itr != options_.end())
		return *itr;
	return empty_;
}

