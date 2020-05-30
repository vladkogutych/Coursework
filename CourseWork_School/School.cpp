#include "School.h"
#include<clocale>

School::School() {
	readFiles();
};

void School::showSchool() {
	setlocale(LC_CTYPE, "ukr");
	cout << "Назва шеколи: " << name << endl <<
		"Число вчителiв: " << teacherCount << endl <<
		"Число учнiв: " << studentCount << endl;
}

School::~School() {};
