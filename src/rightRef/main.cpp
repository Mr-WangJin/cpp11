#include <iostream>
#include <vector>

class MyClassB
{
public:
	MyClassB() {
		m_intval = 0;
	}
	MyClassB(const MyClassB &rgh) {
		m_intval = rgh.m_intval;
	}
	MyClassB(const MyClassB &&rgh) {
		m_intval = rgh.m_intval;
	}
	~MyClassB() {
		m_intval = 0;
	}
	inline void operator=(const MyClassB &&rgh) {
		this->m_intval = rgh.m_intval;
		std::cout << "operator &" << std::endl;
	}
	inline void operator=(const MyClassB &rgh) {
		this->m_intval = rgh.m_intval;
		std::cout << "operator &&" << std::endl;
	}

	int m_intval;
};

int main(void)
{
	MyClassB b1, b2;
	b2.m_intval = 10;
	
	b2 = b1;
	b2 = std::move(b1);			//std::move(),参数可以是左值也可以是右值
	
	system("pause");
}