#pragma once

#include <iostream>       
#include <thread>         
#include <chrono>         


extern void pause_thread(int n);


void testThread2()
{
	std::cout << std::endl << __func__ << std::endl;

	std::thread(pause_thread, 1).detach();		//������detach���̶߳��� joinable Ϊfalse�������̽�����ʱ�򣬼���detachû���������Ҳ�ᱻǿ��ɱ��
	std::thread(pause_thread, 2).detach();
	std::thread t = std::thread(pause_thread, 3);
	t.detach();
	std::cout << t.joinable() << std::endl;


	pause_thread(5);
}