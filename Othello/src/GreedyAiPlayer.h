#ifndef GREEDYAIPLAYER_H_
#define GREEDYAIPLAYER_H_

#include "PlayerIf.h"

class Game;

class GreedyAiPlayer : public PlayerIf {
public:
	GreedyAiPlayer(const Game& g);

	Coords GetInput() override;
private:
	const Game& game;
};

#endif // GREEDYAIPLAYER_H_
