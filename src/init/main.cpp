#include <iostream>  
#include "Company.h"

class Person
{
public:
	std::string name;
	int age;
};


int main()
{
	Person p = { "Frank", 25};
	std::cout<< p.name.c_str() << " : " << p.age << std::endl;

	std::string companyName = "Glodon1";
	Company c(companyName, "private company");
	std::cout << c.m_Name.c_str() << std::endl;

	system("pause");
	return 1;
}