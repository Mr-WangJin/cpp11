
#include <iostream>
using namespace std;

struct A {
	~A() {
		throw 1;
	}
};

struct B {
	~B() noexcept(false) {
		throw 2;
	}
};


struct C {
	B b;
};


int main()
{
	try {
	}
	return 1;
}