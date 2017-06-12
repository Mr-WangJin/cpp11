#pragma once

#include <iostream>       
#include <thread>         
#include <chrono>    

extern void pause_thread(int n);

void testThread1() {
	std::cout << std::endl << __func__ << std::endl;

	std::thread t1(pause_thread, 4);	//�����̣߳�����ʼִ�к���
	std::thread t2(pause_thread, 1);
	std::thread t3(pause_thread, 2);

	t1.join();		//�ȴ� t1 ���������ͷ��߳�t1.���������join�����������std::terminate();
	t2.join();		
	t3.join();

}