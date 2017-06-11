
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


void funA() { A a; }
void funB() { B b; }

int main()
{
	try {
		funB();
	}
	catch (...) {
		std::cout << "caught funB." << std::endl;
	}

	try {
		funA();
	}
	catch(...){
		std::cout << "caught funA." << std::endl;
	}
	return 1;
}