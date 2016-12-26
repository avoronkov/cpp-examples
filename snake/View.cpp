#include "View.h"

#include <ncurses.h>

#include <iostream>
#include <string>

View::View() {
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	timeout(0);

	getmaxyx(stdscr, _sheight, _swidth);
}

View::~View() {
	endwin();
}

void View::update() {
	if (_game->state() == State::Over) {
		std::string mesg{"Game over."};
		// std::cerr << "game over: " << _sheight/2 << ", " << (_swidth-mesg.size())/2 << std::endl;
		mvprintw(_sheight/2, (_swidth-mesg.size())/2, "%s", mesg.c_str());
		refresh();
		return;
	}
	
	processControls();

	clear();
	const auto & snake = _game->snake();
	for (const auto & p : snake) {
		mvaddch(p.y, p.x, '*');
	}
	const Point & f = _game->food();
	mvaddch(f.y, f.x, '#');
	move(_sheight-1, _swidth-1);
	refresh();
}

void View::processControls() {
	int c = getch();
	switch (c) {
		case KEY_UP:    _game->move(Dir::Down); break;
		case KEY_DOWN:  _game->move(Dir::Up); break;
		case KEY_LEFT:  _game->move(Dir::Left); break;
		case KEY_RIGHT: _game->move(Dir::Right); break;
		case KEY_BACKSPACE: _game->cancel(); break;
	}
}
