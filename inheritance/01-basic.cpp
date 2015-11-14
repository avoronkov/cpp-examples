#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Base {
private:
	// private members are accessible only by the class itself (Base)
	int x;
protected:
	// protected members are accessible by the class and its subclasses (Base, Derived)
	int y;
public:
	Base(int _x, int _y): x{_x}, y{_y} {}
	// destructor of superclass should be always virtual!
	virtual ~Base() = default;

	int xy() const { return x * y; }
	// Note that whoAmI is virtual:
	virtual string whoAmI() const { return "I am Base"; }

};

class Derived : public Base {
private:
	int z;
public:
	Derived(int _x, int _y, int _z):
		Base{_x, _y},
		z{_z}
	{}
	virtual ~Derived() = default;
	int yz() const {
		// use y from Base class:
		return y * z;
	}
	// "override" indicates that this method overrides
	// method of base class.
	virtual string whoAmI() const override { return "I am Derived"; }
};


int main() {
	Base* b = new Base{2, 3};
	cout << b->xy() << endl; // 6
	cout << b->whoAmI() << endl; // I am Base
	delete b;

	Derived* d = new Derived{3, 4, 5};
	cout << d->xy() << endl; // 12
	cout << d->yz() << endl; // 20
	cout << d->whoAmI() << endl; // I am Derived
	delete d;

	// Use Derived through pointer to Base:
	Base * bd = new Derived{1, 2, 3};
	cout << bd->whoAmI() << endl; // I am Derived (!)
	delete bd;
}
