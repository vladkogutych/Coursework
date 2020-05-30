#pragma once
#include "Teacher.h"
#include<clocale>
class Lessons :	virtual public Teacher {
	string lessons[7] = { "Англ мова", "Укр мова", "Математика", "Фiзика", "Хiмiя", "Iсторiя", "Фiз вих" };
public:
	Lessons();
	void takeLesson();
	void showLessons();
	~Lessons();
};

