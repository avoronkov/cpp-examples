#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::to_string;

class Base {
protected:
	int x;
public:
	Base(int _x): x{_x} {}
	virtual ~Base() = default;
	virtual string name() const {
		return string("base with x = ") + to_string(x);
	}
};

class Derived : public Base {
private:
	int y;
public:
	Derived(int _x, int _y): Base{_x}, y{_y} {}
	virtual ~Derived() = default;
	virtual string name() const {
		return string("derived with x = ") + to_string(x)
			+ " and y = " + to_string(y);
	}
};

void useNormally(const Base & b) {
	cout << "use " << b.name() << endl;
}

void useSliced(Base b) {
	cout << "use " << b.name() << endl;
}

int main() {
	Derived d{5, 7};
	cout << "I am " << d.name() << endl;

	// only x is copied from d to b:
	Base b = d;
	cout << "I am " << b.name() << endl;

	useNormally(d);
	useSliced(d);
}
