// lock_guard example
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex, std::lock_guard
#include <stdexcept>      // std::logic_error

std::mutex mtx2;

void print_even(int x) {
	if (x % 2 == 0) std::cout << x << " *************** \n";
	else throw (std::logic_error("not even"));
}

void print_thread_id(int id) {
	try {
		std::lock_guard<std::mutex> lck(mtx2);			//lock_guard 防止抛出异常，没有unlock(mtx2)
		//std::unique_lock<std::mutex> lck(mtx2);				//unique_lock 比lock_guard多了一些成员函数，更好用一些
		print_even(id);
	}
	catch (std::logic_error&) {
		std::cout << "[exception caught]\n";
	}
}

void testlockgrard()
{
	std::thread threads[10];
	// spawn 10 threads:
	for (int i = 0; i<10; ++i)
		threads[i] = std::thread(print_thread_id, i + 1);

	for (auto& th : threads) th.join();

}