#ifndef FIELD_H
#define FIELD_H

class Field {
	int _width;
	int _height;

public:
	Field(int w, int h): _width{w}, _height{h} {}
	int width() const { return _width; }
	int height() const { return _height; }
};

#endif 
