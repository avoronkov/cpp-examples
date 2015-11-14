#include <iostream>
#include <string>
#include <cmath> // for sqrt

using std::cout;
using std::endl;
using std::string;

// Classical example about shapes

// Abstract class which describes behavior of shapes
class Shape {
public:
	// All methods are abstract, i.e. have no implementation
	// name of shape
	virtual string name() const = 0;
	// area of shape
	virtual double area() const = 0;
};

class Rectangle : public Shape {
private:
	double width;
	double height;
public:
	Rectangle(double w, double h): width{w}, height{h} {}
	~Rectangle() = default;
	virtual string name() const override { return "Rectangle"; }
	virtual double area() const override { return width * height; }
};

class Circle : public Shape {
private:
	double radius;
public:
	Circle(double r): radius{r} {}
	~Circle() = default;
	virtual string name() const override { return "Circle"; }
	virtual double area() const override { return 3.1416 * radius * radius; }
};

class Triangle : public Shape {
private:
	double a;
	double b;
	double c;
public:
	Triangle(double _a, double _b, double _c):
		a{_a}, b{_b}, c{_c}
	{}
	~Triangle() = default;
	
	virtual string name() const override { return "Triangle"; }
	virtual double area() const override {
		double p = (a + b + c) / 2;
		return sqrt(p * (p-a) * (p-b) * (p-c));
	}
};

void processShape(const Shape & shape) {
	cout << "Working with " << shape.name()
		<< " which has area " << shape.area() << endl;
}

int main() {
	Circle c{1.0};
	Rectangle r{3.0, 4.0};
	Triangle t{3.0, 4.0, 5.0};

	processShape(c);
	processShape(r);
	processShape(t);
}
