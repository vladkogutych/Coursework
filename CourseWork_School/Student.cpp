#include "pch.h"
#include "Student.h"
#include <iomanip>
#include<clocale>

Student::Student(){
	this->grade = 1;
	this->avgMark = 0;
}

Student::Student(int grade, int avgMark) {
	this->grade = grade;
	this->avgMark = avgMark;
}

void Student::setAllStudent() {
	setAllHuman();
	setlocale(LC_CTYPE, "ukr");
	cout << "Введiть ступiнь: " << endl;
	cin >> grade;
	cout << "Введіть середню оцінку: " << endl;
	cin >> avgMark;
}

void Student::setGrade(int grade) {
	this->grade = grade;
}

int Student::getGrade() {
	return grade;
}

void Student::setAvgMark(int avgMark) {
	this->avgMark = avgMark;
}

int Student::getAvgMark() {
	return avgMark;
}

void Student::addStudent() {
	Student *t;
	t = new Student;
	t->setAllStudent();
	students.push_back(*t);
	studentCount++;
}

bool Student::showStudents() {
	setlocale(LC_CTYPE, "ukr");
	if (studentCount != 0) {
		int count = 1;
	
		cout << "Виберiть учня: " << endl;
		for (it = students.begin(); it != students.end(); it++) {
			cout << setw(5) << count << ": ";
			string name = it->getName();
			cout << name << endl;
			count++;
		}
		return true;
	}
	else {
		
		cout << "Вiдсутнi учнi,введiть ще!" << endl;
		return false;
	}
}

int Student::pickStudent() {
	setlocale(LC_CTYPE, "ukr");
	int choice;

	//cout << "Pick student:" << endl;
	if (showStudents() == true) {
		cin >> choice;
		choice--;
		return choice;
	}

	else {
		cout << "Вiдсутнi учнi,введiть ще!" << endl;
	}
}

Student::~Student(){
}
