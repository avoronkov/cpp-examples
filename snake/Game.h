#ifndef GAME_H
#define GAME_H

#include "Field.h"
#include "Snake.h"

#include <random>

enum class State { Cont, Over, Cancel };

class Game {
	Field * _field;
	Snake * _snake;
	State _state;
	Point _food;

	std::random_device rd;
	std::mt19937 gen;

public:
	Game(Field * f, Snake * s);
	void update();
	State state() const { return _state; }

	const Snake & snake() const { return *_snake; }
	const Point & food() const { return _food; }

	// controls
	void move(Dir dir);

	void cancel() { _state = State::Cancel; }
private:
	void placeFood();
};

#endif
