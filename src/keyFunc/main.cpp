#include <iostream>  
#include <assert.h>
#include <vector>

void testAssert() {
	std::cout << std::endl << __func__ << std::endl;

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
		std::cout << __func__ << std::endl;			//����printFunName
		std::cout << __FUNCTION__ << std::endl;		//����A::printFunName
		std::cout << __LINE__ << std::endl;			//�����к�
	}
};

void testFuncKeyWorkd() {
	ABase* a = new A();
	a->printFunName();
	delete a;
}

void testFor() {
	/** 
	 *	���Ա����Ķ��������
	 *	����
	 *	������begin()��end()�������ҷ��ظ÷������ص�����������󡣣�STL ���������������ԣ�
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

using DataArray = std::vector<int>;		//�൱�� typedef std::vector<int> DataArray;
using PrintVal = void(int);

void printVal(int v)
{
	std::cout << v << std::endl;
}
void testUsing() {
	PrintVal* p = printVal;
	p(100);
}

void testDecltype() {
	int i = 10;
	decltype(i) a;			//a�Ƶ�Ϊint
	decltype((i))b = i;		//b�Ƶ�Ϊint&������Ϊ���ʼ��������������

	i += 1;
	std::cout << "test decltype" << std::endl;
	std::cout << b << std::endl;
}

constexpr int getArrayCount(int x, int y) {
	return x * y;
}

void testConstExpr() {
	int Array[getArrayCount(1, 3)] = { 1, 2, 3 };
	for (int var : Array)
	{
		std::cout << var << std::endl;
	}
}


class TestDefaultClass {
public:
	TestDefaultClass() {};                  // default constructor
	~TestDefaultClass() {};                 // destructor

	TestDefaultClass(const TestDefaultClass & rhs) {};         // copy constructor
	TestDefaultClass & operator=(const TestDefaultClass & rhs) {};    // copy assignment operator

	TestDefaultClass(const TestDefaultClass && rhs) {};         // C++11, move constructor
	TestDefaultClass & operator=(TestDefaultClass && rhs) {};    // C++11, move assignment operator
};
class TestDefaultClass1 {
public:
	TestDefaultClass1() = default;
	TestDefaultClass1(int) {};

// 	TestDefaultClass1(const TestDefaultClass1 & rhs) = delete;
// 	TestDefaultClass1 & operator=(const TestDefaultClass1 & rhs) = delete;
// 
// 	TestDefaultClass1(const TestDefaultClass1 && rhs) {};         // C++11, move constructor


};
TestDefaultClass1 t1;
TestDefaultClass1 t2(std::move(t1));

int main()
{
// 	testAssert();
// 	testFuncKeyWorkd();
// 	testFor();
// 	testUsing();
// 	testDecltype();
	testConstExpr();

	system("pause");
}