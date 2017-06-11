
#include <iostream>
#include <assert.h>
using namespace std;


void funA() noexcept { throw "A"; }
void funB() noexcept(false) { throw "B"; }

int main()
{
	try {
		funB();
	}
	catch (...) {
		std::cout << "caught funB." << std::endl;
	}

	try {
		funA();			// 会进入到 std::terminate();
	}
	catch(...){
		std::cout << "caught funA." << std::endl;
	}
	return 1;
}