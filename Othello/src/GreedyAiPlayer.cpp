#include "GreedyAiPlayer.h"

#include <iostream>

#include "Game.h"

GreedyAiPlayer::GreedyAiPlayer(const Game& g) : game(g) {}

Coords GreedyAiPlayer::GetInput() {
	size_t max_captured = 0;
	size_t selected_r = 0;
	size_t selected_c = 0;
	bool move_found = false;
	for (size_t r = 0; r < game.rows_; r++) {
		for (size_t c = 0; c < game.columns_; c++) {
			size_t cur_captured = game.GetCapturedTiles(r, c).size();
			if (cur_captured > max_captured) {
				max_captured = cur_captured;
				selected_r = r;
				selected_c = c;
				move_found = true;
			}
		}
	}
	if (move_found) {
		std::cout << selected_r + 1 << " " << selected_c + 1 << "\n";
	}
	else {
		std::cout << "\nNo move to make.\n";
	}
	return { selected_r, selected_c };
}