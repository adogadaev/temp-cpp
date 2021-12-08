#ifndef CMDLINEPARSER_H_
#define CMDLINEPARSER_H_

#include <string>
#include <vector>

class CmdLineParser {
public:
	CmdLineParser(int& argc, char** argv);
	virtual ~CmdLineParser() = default;

	bool checkOption(const std::string& sOpt) const;
	const std::string& getOption(const std::string& sOpt) const;
private:
	std::vector<std::string> options_;
	static const std::string empty_;
};

#endif // CMDLINEPARSER_H_
