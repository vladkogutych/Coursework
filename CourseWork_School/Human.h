#pragma once
#include<clocale>
#include <iostream>
#include <string>
using namespace std;

class Human {
protected:
	int age,
		money;
	string name,
		sex;
public:
	Human();
	Human(int age, string name, string sex, int money);

	void setAge(int age);
	int getAge();

	void setName(string name);
	string getName();

	void setSex(string sex);
	string getSex();

	void setMoney(int money);
	int getMoney();

	void setAllHuman();

	~Human();
};

