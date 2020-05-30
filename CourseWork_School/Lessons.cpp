
#include "Lessons.h"
#include<clocale>
Lessons::Lessons() { 
}

void Lessons::takeLesson() {
	setlocale(LC_CTYPE, "ukr");
	int choice,
		teacher;
	cout << "��i � ����� �� � ���i�� �i��i����?" << endl;
	for (int i = 0; i < 7; i++) {
		cout << i + 1 << ": " << lessons[i] << endl;
	}
	cin >> choice;
	choice--;
	teacher = searchTeacher(lessons[choice]);
	if (teacher != -1) {
		teachers[teacher].setMoney(getMoney() + 100);
		cout << "���� ������� �����!" << endl <<
			"������� " << teachers[teacher].getName() << " �������� ������." << endl <<
			"������: " << teachers[teacher].getMoney() << endl;
	}
}

void Lessons::showLessons() {
	setlocale(LC_CTYPE, "ukr");
	cout << "����:" << endl;
	for (int i = 0; i < 7; i++) {
		cout << i + 1 << ": " << lessons[i] << endl;
	}
}

Lessons::~Lessons() {}
