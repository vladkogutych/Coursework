
#include "Lessons.h"
#include<clocale>
Lessons::Lessons() { 
}

void Lessons::takeLesson() {
	setlocale(LC_CTYPE, "ukr");
	int choice,
		teacher;
	cout << "якi б уроки ви б хотiли вiдвiдати?" << endl;
	for (int i = 0; i < 7; i++) {
		cout << i + 1 << ": " << lessons[i] << endl;
	}
	cin >> choice;
	choice--;
	teacher = searchTeacher(lessons[choice]);
	if (teacher != -1) {
		teachers[teacher].setMoney(getMoney() + 100);
		cout << "”рок пройшов добре!" << endl <<
			"”читель " << teachers[teacher].getName() << " «аробили грошей." << endl <<
			"√рошей: " << teachers[teacher].getMoney() << endl;
	}
}

void Lessons::showLessons() {
	setlocale(LC_CTYPE, "ukr");
	cout << "”рок:" << endl;
	for (int i = 0; i < 7; i++) {
		cout << i + 1 << ": " << lessons[i] << endl;
	}
}

Lessons::~Lessons() {}
