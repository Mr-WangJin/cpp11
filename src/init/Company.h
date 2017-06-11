#pragma once

#include <string>

class Company {
public:
	Company(const std::string &type) : m_Type(type){
		this->initialize();
	}
	Company(const std::string &name, const std::string &type) : Company(type) {	//�����õ���ί�й��캯��
		m_Name = name;
	};

	~Company() {};

private:
	void initialize() {};

public:
	std::string m_Name = "Glodon";				//����Ĭ��ֵ
	std::string m_Type{"private company"};
};
