#include <iostream>  

struct Person
{
	std::string name;
	int age;
};

int main()
{
	Person p = { "Frank", 25 };
	std::cout<< p.name.c_str() << " : " << p.age << std::endl;

	//long double ld = 3.1415926536;
	//int a{ ld }, b = { ld };		//������������־��ȵĶ�ʧ  
	//int c(ld), d = ld;				// ���б��ʼ�������ǻ���־��ȵĶ�ʧ 

	system("pause");
}