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
	//int a{ ld }, b = { ld };		//出错，不允许出现精度的丢失  
	//int c(ld), d = ld;				// 非列表初始化，但是会出现精度的丢失 

	system("pause");
}