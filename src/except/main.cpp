
#include <iostream>
#include <assert.h>
using namespace std;


void funA() noexcept { throw "A"; }				//�൱�� noexcept(true)
void funB() noexcept(false) { throw "B"; }
void funC() { throw "C"; }


int main()
{
	try {
		funB();
	}
	catch (...) {
		std::cout << "caught funB." << std::endl;
	}

	try {
		funA();			// ����뵽 std::terminate();
	}
	catch(...){
		std::cout << "caught funA." << std::endl;
	}

	try
	{
		funC();
	}
	catch (...)
	{
		std::cout << "caught funC." << std::endl;
	}

	system("pause");
	return 1;
}