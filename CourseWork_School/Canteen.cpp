#include "pch.h"
#include "Canteen.h"
#include <string>
#include <iostream>
#include<clocale>
using namespace std;

Canteen::Canteen(){}

void Canteen::readFiles() {
	setlocale(LC_CTYPE, "ukr");
	foodName.open("foodName.txt");
	foodPrice.open("foodPrice.txt");

	string str, strTemp;
	int prc, prcTemp = 0;

	if (foodName.is_open()) {
		while (true) {
			foodName >> str;
			if (str == strTemp)
				break;
			else {
				food.push_back(str);
				strTemp = str;
			}

			foodPrice >> prc;
			if (prc == prcTemp)
				break;
			else {
			    price.push_back(prc);
				prcTemp = prc;
			}
		}
	}

	else
		cout << "File not found!" << endl;

	foodName.close();
	foodPrice.close();
}

void Canteen::addFood() {
	setlocale(LC_CTYPE, "ukr");
	
	foodName.open("foodName.txt", ios::app);
	foodPrice.open("foodPrice.txt", ios::app);

	int choice = 1;
	string nameTemp;
	int priceTemp;

	while (choice == 1) {
		cout << "��� � ��� �� � ���i�� �����?" << endl;
		cin >> nameTemp;
		cout << "������ " << nameTemp << " �i��:" << endl;
		cin >> priceTemp;

		foodName << nameTemp << endl;
		foodPrice << " " << priceTemp << " ";

		cout << "������� ?" << endl << "1 - ���" << endl << "0 - �i" << endl;
		cin >> choice;
	}

	foodName.close();
	foodPrice.close();
}

void Canteen::sellFood() {
	setlocale(LC_CTYPE, "ukr");
	int choice2;
	cout << "��� ���� �������� ��� ?" << endl <<
		"1 - �������" << endl <<
		"2 - �����" << endl;
	cin >> choice2;
	if (choice2 == 1) {
		if (teacherCount != 0) {
			int choice = pickTeacher(),
				choice1;
			cout << "��� ��� �� � ���i�� �������� ?" << endl;
			for (int i = 0; i < food.size(); i++) {
				cout << i + 1 << ": " << food[i] << " - " << price[i] << endl;
			}
			cin >> choice1;
			choice1--;
			teachers[choice].setMoney(teachers[choice].getMoney() - price[choice1]);
			cout << food[choice1] << " successfully bought !" << endl <<
				"������� ������: " << teachers[choice].getMoney() << "$" << endl;
		}
		else
			cout << "��� ���� ������i� !" << endl;
	}
	else if (choice2 == 2) {
		if (studentCount != 0) {
			int choice = pickStudent(),
				choice1;
			cout << "��� ��� �� � ���i�� �������� ?" << endl;
			showFood();
			cin >> choice1;
			choice1--;
			students[choice].setMoney(getMoney() - price[choice1]);
			cout << food[choice1] << " ������� !" << endl <<
				"������� ������: " << students[choice].getMoney() << endl;
		}
		else
			cout << "��� ���� ���i� !" << endl;
	}
}

void Canteen::showFood() {
	setlocale(LC_CTYPE, "ukr");
	cout << "�������� ��� � ������i" << endl;
	for (int i = 0; i < food.size(); i++) {
		cout << i + 1 << ": " << food[i] << " - " << price[i] << "$" << endl;
	}
}

Canteen::~Canteen(){}
