#ifndef VIEW_H
#define VIEW_H

#include "Game.h"

class View {
	int _swidth;
	int _sheight;
	Game * _game;
public:
	View();
	~View();
	int screenWidth() const { return _swidth; }
	int screenHeight() const { return _sheight; }

	void setGame(Game * g) {
		_game = g;
	}

	void refreshScreen();
	void processControls();
};


#endif
