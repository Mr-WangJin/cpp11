#pragma once

#include <iostream>       // std::cout
#include <functional>     // std::ref
#include <thread>         // std::thread
#include <future>         // std::promise, std::future

extern void pause_thread(int n);

void print_int(std::future<int>& fut) {

	std::future_status status;
	do {
		status = fut.wait_for(std::chrono::seconds(1));
		if (status == std::future_status::deferred) {
			std::cout << "deferred\n";
		}
		else if (status == std::future_status::timeout) {
			std::cout << "timeout\n";
		}
		else if (status == std::future_status::ready) {
			std::cout << "ready!\n";
		}
	} while (status != std::future_status::ready);

	int x = fut.get();
	std::cout << "value: " << x << '\n';
}

void setPromiseFutValue(std::promise<int>& p) {
	pause_thread(5);

	p.set_value(10);
}

void testThread3() {
	std::cout << std::endl << __func__ << std::endl;

	std::promise<int> prom;                      // ����һ�� promise    //promise ��װ��һ��������ʹ��fuure�����ݵ�һ������

	std::future<int> fut = prom.get_future();    //  �� future ����

	std::thread th1(print_int, std::ref(fut));  // �� future ��������һ���߳�t.

	std::thread(setPromiseFutValue, std::ref(prom)).detach();
												
	th1.join();


}
