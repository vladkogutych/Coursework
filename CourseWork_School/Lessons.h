#pragma once
#include "Teacher.h"
#include<clocale>
class Lessons :	virtual public Teacher {
	string lessons[7] = { "���� ����", "��� ����", "����������", "�i����", "�i�i�", "I����i�", "�i� ���" };
public:
	Lessons();
	void takeLesson();
	void showLessons();
	~Lessons();
};

