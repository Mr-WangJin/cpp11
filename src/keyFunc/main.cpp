#include <iostream>  
#include <assert.h>

void testAssert() {

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
		std::cout << __func__ << std::endl;
	}
};

int main()
{
	testAssert();

	ABase* a = new A();
	a->printFunName();

	system("pause");
}