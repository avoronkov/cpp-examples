#ifndef POINT_H
#define POINT_H

#include <iostream>

struct Point {
	int x;
	int y;
	bool operator==(const Point & p) const {
		return x == p.x && y == p.y;
	}
	bool operator!=(const Point & p) const {
		return !((*this) == p);
	}
};

std::ostream& operator<<(std::ostream & out, const Point & p);

#endif
