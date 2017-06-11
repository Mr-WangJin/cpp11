#pragma once

#include <string>

class Company {
public:
	Company(const std::string &type) : m_Type(type){
		this->initialize();
	}
	Company(const std::string &name, const std::string &type) : Company(type) {	//这里用到了委托构造函数
		m_Name = name;
	};

	~Company() {};

private:
	void initialize() {};

public:
	std::string m_Name = "Glodon";				//设置默认值
	std::string m_Type{"private company"};
};
