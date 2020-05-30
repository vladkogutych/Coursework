#pragma once
#include<clocale>
#include "Human.h"
#include <vector>

class Student : virtual public Human{
protected:
	int grade,
		avgMark;
	vector <Student> students;
	vector <Student>::iterator it;
	int studentCount;
public:
	Student();
	Student(int grade, int avgMark);
	void setGrade(int grade);
	int getGrade();
	void setAvgMark(int avgMark);
	int getAvgMark();
	void setAllStudent();
	void addStudent();
	int pickStudent();
	bool showStudents();
	~Student();
};

