#pragma once
#include <vector>
#include <fstream>
#include "Student.h"
#include "Teacher.h"
#include<clocale>
using namespace std;

class Canteen : virtual public Student, virtual public Teacher {
protected:
	vector <string> food;
	vector <int> price;
	int profit;
	fstream foodName;
	fstream foodPrice;
public:
	Canteen();
	
	void readFiles();

	void addFood();

	void sellFood();

	void showFood();

	~Canteen();
};

