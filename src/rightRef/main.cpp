#include <iostream>

class MyClassB
{
public:
	void init(int & intval)
	{
		std::cout << "use & print" << std::endl;
	};
	void init(int &&intval)
	{
		intval = 11;
		std::cout << "use && print" << std::endl;
	}
};

int main(void)
{
	int ae = 10;
	MyClassB().init(10);
	MyClassB().init(ae);
	
	system("pause");
}