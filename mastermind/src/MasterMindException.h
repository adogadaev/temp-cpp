#ifndef MASTERMINDEXCEPTION_H_
#define MASTERMINDEXCEPTION_H_

#include <stdexcept>
#include <string>

class MasterMindException : public std::runtime_error {
public:
	MasterMindException(const std::string& message)
	        : std::runtime_error(message) { };
};

#endif /* MASTERMINDEXCEPTION_H_ */
