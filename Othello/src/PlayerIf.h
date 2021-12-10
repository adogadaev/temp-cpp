#ifndef PLAYER_H_
#define PLAYER_H_

struct Coords {
	size_t row;
	size_t column;
};

class PlayerIf {
public:
	PlayerIf() = default;
	virtual ~PlayerIf() = default;

	virtual Coords GetInput() = 0;
};

#endif // PLAYER_H_