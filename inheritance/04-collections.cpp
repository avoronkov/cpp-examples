#include <iostream>
#include <string>
#include <vector>
#include <memory>

using std::cout;
using std::endl;
using std::string;
using std::vector;

// Describe Base class

class Base {
public:
	Base() = default;
	virtual ~Base() = default;
	virtual std::ostream& put(std::ostream & out) const {
		return out << "base";
	}
};

std::ostream& operator<<(std::ostream & out, const Base & obj) {
	return obj.put(out);
}

// Describe some subclasses

class A : public Base {
private:
	int a;
public:
	A(int _a): a{_a} {}
	virtual ~A() = default;
	virtual std::ostream& put(std::ostream & out) const override {
		return out << "A(" << a << ")";
	}
};

class B : public Base {
private:
	int b;
public:
	B(int _b): b{_b} {}
	virtual ~B() = default;
	virtual std::ostream& put(std::ostream & out) const override {
		return out << "B(" << b << ")";
	}
};

class C : public Base {
private:
	int c;
public:
	C(int _c): c{_c} {}
	virtual ~C() = default;
	virtual std::ostream& put(std::ostream & out) const override {
		return out << "C(" << c << ")";
	}
};

int main() {
	// 1
	vector<Base> v1 = {
		A{10},
		B{20},
		C{30},
	};
	// Too bad: all objects were sliced to Base :(
	for (Base & b : v1) {
		cout << b << endl;
	}
	// output: base base base
	
	// 2
	vector<Base*> v2 = {
		new A{11},
		new B{21},
		new C{31},
	};
	for (Base* b : v2) {
		cout << *b << endl;
	}
	// output: A(11) B(21) C(31)
	// Works correct, but you need to delete objects manually before vector is destroyed
	for (Base* b : v2) {
		delete b;
	}

	// 3
	vector<std::shared_ptr<Base>> v3 = {
		std::make_shared<A>(12),
		std::make_shared<B>(22),
		std::make_shared<C>(32),
	};
	for (std::shared_ptr<Base> b : v3) {
		cout << *b << endl;
	}
	// output: A(12) B(22) C(32)
	// Works correct and objects in collection will be deleted automatically :)
}
