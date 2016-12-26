#include "Point.h"

std::ostream& operator<<(std::ostream & out, const Point & p) {
	return out << p.x << "," << p.y;
}
