#pragma once

#include <iostream>       // std::cout
#include <future>         // std::async, std::future

// a non-optimized way of checking for prime numbers:
bool is_prime(int x) {
	std::cout << "Calculating. Please, wait...\n";
	for (int i = 2; i<x; ++i) if (x%i == 0) return false;
	return true;
}

void testThread4() {
	// call is_prime(313222313) asynchronously:
	std::future<bool> fut = std::async(is_prime, 313222313);		//д╛хо std::launch::async.	

	std::cout << "Checking whether 313222313 is prime.\n";
	// ...

	bool ret = fut.get();      // waits for is_prime to return

	if (ret) std::cout << "It is prime!\n";
	else std::cout << "It is not prime.\n";
}
