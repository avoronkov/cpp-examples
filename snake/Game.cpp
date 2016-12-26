#include "Game.h"
#include <iostream>

#include <random>

Game::Game(Field * f, Snake * s):
	_field{f},
	_snake{s},
	_state{State::Cont},
	rd{},
	gen{rd()}
{
	placeFood();
}

void Game::update() {
	if (_state == State::Over) {
		return;
	}
	if (!_snake->move()) {
		_state = State::Over;
		return;
	}
	for (const auto & p: *_snake) {
		if (p.x < 0 || p.x >= _field->width() ||
			p.y < 0 || p.y >= _field->height()) {
			_state = State::Over;
			return;
		}
		if (p == _food) {
			_snake->grow();
			placeFood();
		}
	}
}

void Game::placeFood() {
	std::uniform_int_distribution<> disx(0, _field->width()-1);
	int x = disx(gen);
	std::uniform_int_distribution<> disy(0, _field->height()-1);
	int y = disy(gen);

	_food = {x, y};
}

void Game::move(Dir dir) {
	_snake->setDir(dir);
}
