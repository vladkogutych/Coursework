#include "pch.h"
#include "Human.h"
#include<clocale>

Human::Human(){
	setlocale(LC_CTYPE, "ukr");
	this->age = 0;
	this->name = "Невiдомо";
	this->sex = "Невiдомо";
	this->money = 0;
}

Human::Human(int age, string name, string sex, int money) {
	this->age = age;
	this->name = name;
	this->sex = sex;
	this->money = money;
}

void Human::setAllHuman() {
	setlocale(LC_CTYPE, "ukr");
	cout << "Введiть iмя: " << endl;
	cin >> name;
	cout << "Введiть вiк: " << endl;
	cin >> age;
	cout << "Введiть стать: " << endl;
	cin >> sex;
}

void Human::setAge(int age) {
	this->age = age;
}

int Human::getAge() {
	return age;
}

void Human::setName(string name) {
	this->name = name;
}

string Human::getName(){
	return name;
}

void Human::setSex(string sex) {
	this->sex = sex;
}

string Human::getSex() {
	return sex;
}

void Human::setMoney(int money) {
	this->money = money;
}

int Human::getMoney() {
	return money;
}

Human::~Human(){
}
