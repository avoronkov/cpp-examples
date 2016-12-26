#include "Snake.h"
#include <iostream>

namespace {
	inline void movePointToDir(Point & p, Dir dir) {
		switch (dir) {
			case Dir::Up:    p.y+=1; break;
			case Dir::Down:  p.y-=1; break;
			case Dir::Left:  p.x-=1; break;
			case Dir::Right: p.x+=1; break;
		}
	}
}

Snake::Snake(int xpos, int ypos):
	_direction{Dir::Up},
	_body{ Point{xpos, ypos}, Point{xpos, ypos-1} },
	_grow{false}
{
}

/* true on success
 * false on crashing with itself
 */
bool Snake::move() {
	Point head = *(_body.begin());
	movePointToDir(head, _direction);
	for (const auto & p: _body) {
		if (head == p) {
			return false;
		}
	}
	_body.push_front(head);
	if (!_grow) {
		_body.pop_back();
	}
	_grow = false;
	return true;
}

bool Snake::setDir(Dir dir) {
	Point h = *(_body.begin());
	movePointToDir(h, dir);
	const Point & neck = *(++(_body.begin()));
	if (h != neck) {
		_direction = dir;
		return true;
	}
	return false;
}

void Snake::put(std::ostream & out) const {
	const char * pref = "";
	for (const auto & p: _body) {
		out << pref << p;
		pref = " ";
	}
}

std::ostream& operator<<(std::ostream& out, const Snake & s) {
	s.put(out);
	return out;
}
