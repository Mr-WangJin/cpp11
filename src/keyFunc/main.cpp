#include <iostream>  
#include <assert.h>
#include <vector>

void testAssert() {
	std::cout << std::endl << __func__ << std::endl;

	static_assert(sizeof(int) == 4, " int equal 4 bits ");		//程序编译时就会检测
	assert(sizeof(int) == 4);									//程序运行时检测
}

template<typename T> class Person {
	friend T;
};
//Person<A> aa; 类型A在这里是Person类型的友元
//Person<int> aa; 对于int类型，友元申明被忽略

class ABase {
public:
	virtual void printName() = 0;
	virtual void printFunName() = 0;
};
class A : public ABase{
public:
	virtual void printName() override {
		std::cout << "Name" << std::endl;
	}
	virtual void printFunName() final {
		std::cout << __func__ << std::endl;			//返回printFunName
		std::cout << __FUNCTION__ << std::endl;		//返回A::printFunName
		std::cout << __LINE__ << std::endl;			//返回行号
	}
};

void testFor() {
	/** 
	 *	可以遍历的对象包括：
	 *	数组
	 *	定义了begin()和end()方法，且返回该方法返回迭代器的类对象。（STL 中所有容器都可以）
	 */
	std::vector<int> c{ 1,2,3,4,5 };
	for (auto i : c){
		std::cout << i << std::endl;
	}
	int dataArray[] = { 5, 6, 7, 8, 9 };
	for (auto &i : dataArray)
	{
		std::cout << i << std::endl;
	}
}

using DataArray = std::vector<int>;		//相当于 typedef std::vector<int> DataArray;
using PrintVal = void(int);

void printVal(int v)
{
	std::cout << v << std::endl;
}
void testUsing() {
	PrintVal* p = printVal;
	p(100);
}



int main()
{
	testAssert();

	ABase* a = new A();
	a->printFunName();

	testFor();
	testUsing();

	system("pause");
}