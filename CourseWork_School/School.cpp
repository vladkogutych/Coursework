#include "School.h"
#include<clocale>

School::School() {
	readFiles();
};

void School::showSchool() {
	setlocale(LC_CTYPE, "ukr");
	cout << "����� ������: " << name << endl <<
		"����� ������i�: " << teacherCount << endl <<
		"����� ���i�: " << studentCount << endl;
}

School::~School() {};
