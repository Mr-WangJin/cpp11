#pragma once
// condition_variable example
#include <iostream>           // std::cout
#include <thread>             // std::thread
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void print_id(int id) {
	std::unique_lock<std::mutex> lck(mtx);
	while (!ready) 
		cv.wait(lck);
	std::cout << "thread " << id << '\n';
}

void go() {
	std::unique_lock<std::mutex> lck(mtx);
	ready = true;
	cv.notify_all();
}

void testThread6()
{
	constexpr int arrySize = 5;
	std::thread threads[arrySize];
	// spawn  threads:
	for (int i = 0; i<arrySize; ++i)
		threads[i] = std::thread(print_id, i);

	std::cout << "arrySize threads ready to race...\n";
	go();                       // go!

	for (auto& th : threads) 
		th.join();
}