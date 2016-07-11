/*
 * cWordCounter.h
 *
 *  Created on: Jul 11, 2016
 *      Author: dan
 */

#ifndef CWORDCOUNTER_H_
#define CWORDCOUNTER_H_

#include <string>
#include <unordered_map>
#include <fstream>

class cWordCounter {
public:
	cWordCounter();
	virtual ~cWordCounter();

	void countWords(std::string &line);
	std::unordered_map<std::string,unsigned int> getResult();
private:
	std::unordered_map<std::string,unsigned int> mpHash;
};

#endif /* CWORDCOUNTER_H_ */
