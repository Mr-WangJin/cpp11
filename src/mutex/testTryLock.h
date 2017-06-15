// std::lock example
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex, std::try_lock

std::mutex foo, bar;

void task_a() {
	foo.lock();
	std::cout << "task a\n";
	bar.lock();
	// ...
	foo.unlock();
	bar.unlock();
}

void task_b() {
	int x = try_lock(bar, foo);  //返回-1 表示成功，否则那个失败返回索引值
	if (x == -1) {
		std::cout << "task b\n";
		// ...
		bar.unlock();
		foo.unlock();
	}
	else {
		std::cout << "[task b failed: mutex " << (x ? "foo" : "bar") << " locked]\n";
	}
}

void testTryLock()
{
	std::thread th1(task_a);
	std::thread th2(task_b);

	th1.join();
	th2.join();

}