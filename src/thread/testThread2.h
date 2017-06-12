#pragma once

#include <iostream>       
#include <thread>         
#include <chrono>         


extern void pause_thread(int n);


void testThread2()
{
	std::cout << std::endl << __func__ << std::endl;

	std::thread(pause_thread, 1).detach();		//调用了detach，线程对象 joinable 为false，当进程结束的时候，即便detach没有完成任务也会被强制杀死
	std::thread(pause_thread, 2).detach();
	std::thread t = std::thread(pause_thread, 3);
	t.detach();
	std::cout << t.joinable() << std::endl;


	pause_thread(5);
}