#ifndef GAME_H_
#define GAME_H_

#include <array>
#include <cstdint>
#include <list>

#include "IteratorRange.h"

enum class TileState : uint8_t {
	EMPTY = 0U,
	BLACK = 1U,
	WHITE = 2U
};

class Game {
public:
	static const size_t rows_ = 8;
	static const size_t columns_ = 8;
private:
	using Board = std::array<TileState, rows_* columns_>;
	
public:
	explicit Game();
	virtual ~Game() = default;

	inline size_t GetCurPlayer() const { return (size_t)cur_player_; }
	inline bool IsGameOver() const { return game_over_; }
	inline const std::array<size_t, 2>& GetScore() const { return score_; }
	IteratorRange<Board::const_iterator> GetGameState() const;
	std::list<std::pair<size_t, size_t>> GetCapturedTiles(const size_t r, const size_t c) const;
	
	bool SetTile(const size_t r, const size_t y);
	void SkipMove();
private:
	inline TileState& GetTile(const size_t r, const size_t c) { return board_[r * columns_ + c]; };
	inline const TileState& GetTile(const size_t r, const size_t c) const { return board_[r * columns_ + c]; };
	
	std::list<std::pair<size_t, size_t>> CheckVertical(const size_t r, const size_t c) const;
	std::list<std::pair<size_t, size_t>> CheckHorizontal(const size_t r, const size_t c) const;
	std::list<std::pair<size_t, size_t>> CheckDiagonals(const size_t r, const size_t c) const;

	Board board_;
	std::array<size_t, 2> score_;
	TileState cur_player_;
	bool game_over_;
	bool both_skipped_;
};

#endif // GAME_H_
