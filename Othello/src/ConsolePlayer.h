#ifndef CONSOLEPLAYER_H_
#define CONSOLEPLAYER_H_

#include "PlayerIf.h"

#include <iostream>

class ConsolePlayer : public PlayerIf {
public:
	Coords GetInput() override {
		size_t r, c;
		std::cin >> r >> c;
		return { r - 1, c - 1 };
	}
};

#endif // CONSOLEPLAYER_H_