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



int main()
{
	testAssert();

	ABase* a = new A();
	a->printFunName();

	testFor();
	testUsing();

	system("pause");
}