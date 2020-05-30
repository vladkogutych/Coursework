#pragma once
#include "Canteen.h"
#include "Lessons.h"
#include<clocale>

class School : virtual public Canteen, virtual public Lessons {
protected:
	string name;
public:
	School();
	void showSchool();
	~School();
};

