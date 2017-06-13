#include <iostream>       
#include <thread>
#include "testThread1.h"
#include "testThread2.h"
#include "testThread3.h"
#include "testThread4.h"
#include "testThread5.h"

void pause_thread(int n)
{
	std::this_thread::sleep_for(std::chrono::seconds(n));
	std::cout << "pause of " << n << " seconds ended\n";
}

int main()
{
	//testThread1();
	//testThread2();
	testThread3();
	//testThread4();
	//testThread5();

	system("pause");
	return 0;
}