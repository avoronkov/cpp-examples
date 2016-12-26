#ifndef SNAKE_H
#define SNAKE_H

#include <list>
#include <iostream>

#include "Point.h"

enum class Dir{ Up, Down, Left, Right };

class Snake {
	Dir _direction;
	std::list<Point> _body;
	bool _grow;
public:
	Snake(int xpos, int ypos);
	bool move();
	void grow() { _grow = true; }
	std::list<Point>::const_iterator begin() const {
		return _body.begin();
	}
	std::list<Point>::const_iterator end() const {
		return _body.end();
	}
	bool setDir(Dir dir); 
	void put(std::ostream & out) const;
};

std::ostream& operator<<(std::ostream& out, const Snake & s);

#endif
