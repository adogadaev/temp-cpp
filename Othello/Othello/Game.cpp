#include "Game.h"

Game::Game() : cur_player_(TileState::BLACK), game_over_(false), both_skipped_(false) {
	board_.fill(TileState::EMPTY);
	GetTile(3, 3) = TileState::WHITE;
	GetTile(4, 4) = TileState::WHITE;
	GetTile(3, 4) = TileState::BLACK;
	GetTile(4, 3) = TileState::BLACK;
	score_.fill(2);
}

IteratorRange<Game::Board::const_iterator> Game::GetGameState() const {
	return IteratorRange(board_.cbegin(), board_.cend()); 
}

bool Game::SetTile(const size_t r, const size_t c) {
	std::list<std::pair<size_t, size_t>> captured_tiles = GetCapturedTiles(r, c);
	if (captured_tiles.size() == 0) {
		return false;
	}
	GetTile(r, c) = cur_player_;
	for (const auto& coord : captured_tiles) {
		GetTile(coord.first, coord.second) = cur_player_;
	}

	score_[(size_t)cur_player_ - 1] += (captured_tiles.size() + 1);
	cur_player_ = (cur_player_ == TileState::BLACK) ? TileState::WHITE : TileState::BLACK;
	score_[(size_t)cur_player_ - 1] -= captured_tiles.size();
	both_skipped_ = false;
	
	return true;
}

void Game::SkipMove() {
	if (both_skipped_) {
		game_over_ = true;
	}
	cur_player_ = (cur_player_ == TileState::BLACK) ? TileState::WHITE : TileState::BLACK;
	both_skipped_ = true;
}

std::list<std::pair<size_t, size_t>> Game::GetCapturedTiles(const size_t r, const size_t c) const {
	std::list<std::pair<size_t, size_t>> captured_tiles;
	if (r < rows_ && c < columns_ && GetTile(r, c) == TileState::EMPTY) {
		captured_tiles.splice(captured_tiles.end(), CheckVertical(r, c));
		captured_tiles.splice(captured_tiles.end(), CheckHorizontal(r, c));
		captured_tiles.splice(captured_tiles.end(), CheckDiagonals(r, c));
	}
	return std::move(captured_tiles);
}

std::list<std::pair<size_t, size_t>> Game::CheckVertical(const size_t r, const size_t c) const {
	std::list<std::pair<size_t, size_t>> captured_tiles;
	TileState enemy = (cur_player_ == TileState::BLACK) ? TileState::WHITE : TileState::BLACK;
	
	int i = (int)r - 1;
	size_t captured_num = 0;
	while (i >= 0 && GetTile(i, c) == enemy) {
		captured_tiles.push_back({ i, c });
		i--; captured_num++;
	}
	if ((i >= 0 && captured_num > 0 && GetTile(i, c) == cur_player_) == false) {
		for (; captured_num != 0; captured_num--) {
			captured_tiles.pop_back();
		}
	}

	captured_num = 0;
	i = (int)r + 1;
	while (i < rows_ && GetTile(i, c) == enemy) {
		captured_tiles.push_back({ i, c });
		i++; captured_num++;
	}
	if ((i < rows_ && captured_num > 0 && GetTile(i, c) == cur_player_) == false) {
		for (; captured_num != 0; captured_num--) {
			captured_tiles.pop_back();
		}
	}

	return std::move(captured_tiles);
}

std::list<std::pair<size_t, size_t>> Game::CheckHorizontal(const size_t r, const size_t c) const {
	std::list<std::pair<size_t, size_t>> captured_tiles;
	TileState enemy = (cur_player_ == TileState::BLACK) ? TileState::WHITE : TileState::BLACK;

	size_t captured_num = 0;
	int j = (int)c - 1;
	while (j >= 0 && GetTile(r, j) == enemy) {
		captured_tiles.push_back({ r, j });
		j--; captured_num++;
	}
	if ((j >= 0 && captured_num > 0 && GetTile(r, j) == cur_player_) == false) {
		for (; captured_num != 0; captured_num--) {
			captured_tiles.pop_back();
		}
	}

	captured_num = 0;
	j = (int)c + 1;
	while (j < columns_ && GetTile(r, j) == enemy) {
		captured_tiles.push_back({ r, j });
		j++; captured_num++;
	}
	if ((j < columns_ && captured_num > 0 && GetTile(r, j) == cur_player_) == false) {
		for (; captured_num != 0; captured_num--) {
			captured_tiles.pop_back();
		}
	}

	return std::move(captured_tiles);
}

std::list<std::pair<size_t, size_t>> Game::CheckDiagonals(const size_t r, const size_t c) const {
	std::list<std::pair<size_t, size_t>> captured_tiles;
	TileState enemy = (cur_player_ == TileState::BLACK) ? TileState::WHITE : TileState::BLACK;

	size_t captured_num = 0;
	int i = (int)r - 1;
	int j = (int)c - 1;
	while (i >= 0 && j >= 0 && GetTile(i, j) == enemy) {
		captured_tiles.push_back({ i, j });
		i--; j--; captured_num++;
	}
	if ((i >= 0 && j >= 0 && captured_num > 0 && GetTile(i, j) == cur_player_) == false) {
		for (; captured_num != 0; captured_num--) {
			captured_tiles.pop_back();
		}
	}

	captured_num = 0;
	i = (int)r + 1;
	j = (int)c + 1;
	while (i < rows_ && j < columns_ && GetTile(i, j) == enemy) {
		captured_tiles.push_back({ i, j });
		i++; j++; captured_num++;
	}
	if ((i < rows_ && j < columns_ && captured_num > 0 && GetTile(i, j) == cur_player_) == false) {
		for (; captured_num != 0; captured_num--) {
			captured_tiles.pop_back();
		}
	}

	captured_num = 0;
	i = (int)r + 1;
	j = (int)c - 1;
	while (i < rows_ && j >= 0 && GetTile(i, j) == enemy) {
		captured_tiles.push_back({ i, j });
		i++; j--; captured_num++;
	}
	if ((i < rows_ && j >= 0 && captured_num > 0 && GetTile(i, j) == cur_player_) == false) {
		for (; captured_num != 0; captured_num--) {
			captured_tiles.pop_back();
		}
	}

	captured_num = 0;
	i = (int)r - 1;
	j = (int)c + 1;
	while (i >= 0 && j < columns_ && GetTile(i, j) == enemy) {
		captured_tiles.push_back({ i, j });
		i--; j++; captured_num++;
	}
	if ((i >= 0 && j < columns_ && captured_num > 0 && GetTile(i, j) == cur_player_) == false) {
		for (; captured_num != 0; captured_num--) {
			captured_tiles.pop_back();
		}
	}

	return std::move(captured_tiles);
}