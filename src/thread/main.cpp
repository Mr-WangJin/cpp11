#include <iostream>       
#include <thread>
#include "testThread1.h"
#include "testThread2.h"
#include "testThread3.h"


void pause_thread(int n)
{
	std::this_thread::sleep_for(std::chrono::seconds(n));
	std::cout << "pause of " << n << " seconds ended\n";
}

int main()
{
	testThread1();
	testThread2();
	
	system("pause");
	return 0;
}