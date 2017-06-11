#include <iostream>  
#include <assert.h>

void testAssert() {

	static_assert(sizeof(int) == 4, " int equal 4 bits ");		//�������ʱ�ͻ���
	assert(sizeof(int) == 4);									//��������ʱ���
}

template<typename T> class Person {
	friend T;
};
//Person<A> aa; ����A��������Person���͵���Ԫ
//Person<int> aa; ����int���ͣ���Ԫ����������

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