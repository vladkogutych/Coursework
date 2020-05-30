#include "pch.h"
#include "Teacher.h"
#include <iomanip>
#include<clocale>
Teacher::Teacher(){
	setlocale(LC_CTYPE, "ukr");
	this->experince = 0;
	this->object = "Невiдомо";
}

Teacher::Teacher(int experience, string object) {
	this->experince = experience;
	this->object = object;
}

void Teacher::setExperience(int experience) {
	this->experince = experience;
}

int Teacher::getExperience() {
	return experince;
}

void Teacher::setObject(string object) {
	this->object = object;
}

string Teacher::getObject() {
	return object;
}

void Teacher::setAllTeacher() {
	setAllHuman();
	setlocale(LC_CTYPE, "ukr");
	cout << "Введiть досвiд роботи: " << endl;
	cin >> experince;
	cout << "Виберiть предмет: " << endl;
	cin >> object;
}

void Teacher::addTeacher() {
	Teacher *t;
	t = new Teacher;
	t->setAllTeacher();
	teachers.push_back(*t);
	teacherCount++;
}

bool Teacher::showTeacher() {
	setlocale(LC_CTYPE, "ukr");
	if (teacherCount != 0) {
		int count = 1;
		cout << "Виберiть вчителя: " << endl;
		for (it = teachers.begin(); it != teachers.end(); it++) {
			cout << setw(5) << count << ": ";
			string name = it->getName();
			cout << name << endl;
			count++;
		}
		return true;
	}
	else {
		cout << "Нема вчителiв,добавте!" << endl;
		return false;
	}
}

int Teacher::pickTeacher() {
	setlocale(LC_CTYPE, "ukr");
	int choice;
	//cout << "Pick Teacher:" << endl;
	if (showTeacher() == true) {
		cin >> choice;
		choice--;
		return choice;
	}

	else {
		cout << "Нема вчителiв,добавте!" << endl;
	}
}

int Teacher::searchTeacher(string lesson) {
	setlocale(LC_CTYPE, "ukr");
	int count = 0,
		choice;
	for (int i = 0; i < teachers.size(); i++) {
		if (teachers[i].getObject() == lesson) {
			count++;
			cout << i + 1 << ": " << teachers[i].getName() << " Доступний" <<  endl;
		}
		else {
			cout << i + 1 << ": " << teachers[i].getName() << " Недоступний" << endl;
		}
	}
	if (count == 0) {
		cout << "Нема вiльних вчителiв для цього уроку !" << endl;
		return -1;
	}

	else {
		cout << "Якого вчителя ви хочете обрати ?" << endl;
		cin >> choice;
		choice--;
		return choice;
	}
}

int Teacher::getTeacherCount() {
	return teacherCount;
}

Teacher::~Teacher() {}
