#ifndef TIMER_H
#define TIMER_H

#include "View.h"
#include "Game.h"

class Timer {
	Game * _game;
	View * _view;
	int _freq;
public:
	Timer(Game * g, View * v):
		_game{g},
		_view{v},
		_freq{200}
	{}
	void setFreq(int freq) {
		_freq = freq;
	}
	void start();
};

#endif
