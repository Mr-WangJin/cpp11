#pragma once

#include <iostream>       
#include <thread>         
#include <chrono>    

extern void pause_thread(int n);

void testThread1() {
	std::cout << std::endl << __func__ << std::endl;

	std::thread t1(pause_thread, 4);	//创建线程，并开始执行函数
	std::thread t2(pause_thread, 1);
	std::thread t3(pause_thread, 2);

	t1.join();		//等待 t1 结束，并释放线程t1.如果不调用join，则程序会进入std::terminate();
	t2.join();		
	t3.join();

}