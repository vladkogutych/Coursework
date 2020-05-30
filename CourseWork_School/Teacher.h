#pragma once
#include "Human.h"
#include <vector>
#include<clocale>
class Teacher : virtual public Human{
protected:
	int experince,
		teacherCount;
	string object;
	vector <Teacher> teachers;
	vector <Teacher>::iterator it;
public:
	Teacher();
	Teacher(int experience, string object);
	void setExperience(int experience);
	int getExperience();
	void setObject(string object);
	string getObject();
	void addTeacher();
	int pickTeacher();
	bool showTeacher();
	void setAllTeacher();
	int searchTeacher(string lesson);
	int getTeacherCount();
	~Teacher();
};

