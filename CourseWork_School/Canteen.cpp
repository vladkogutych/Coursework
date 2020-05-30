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
		cout << "Яку б їжу ви б хотiли взяти?" << endl;
		cin >> nameTemp;
		cout << "Введіть " << nameTemp << " цiна:" << endl;
		cin >> priceTemp;

		foodName << nameTemp << endl;
		foodPrice << " " << priceTemp << " ";

		cout << "Добавки ?" << endl << "1 - так" << endl << "0 - нi" << endl;
		cin >> choice;
	}

	foodName.close();
	foodPrice.close();
}

void Canteen::sellFood() {
	setlocale(LC_CTYPE, "ukr");
	int choice2;
	cout << "Хто хоче придбати їжу ?" << endl <<
		"1 - Вчитель" << endl <<
		"2 - Учень" << endl;
	cin >> choice2;
	if (choice2 == 1) {
		if (teacherCount != 0) {
			int choice = pickTeacher(),
				choice1;
			cout << "Яку їжу ви б хотiли придбати ?" << endl;
			for (int i = 0; i < food.size(); i++) {
				cout << i + 1 << ": " << food[i] << " - " << price[i] << endl;
			}
			cin >> choice1;
			choice1--;
			teachers[choice].setMoney(teachers[choice].getMoney() - price[choice1]);
			cout << food[choice1] << " successfully bought !" << endl <<
				"Залишок грошей: " << teachers[choice].getMoney() << "$" << endl;
		}
		else
			cout << "Тут нема вчителiв !" << endl;
	}
	else if (choice2 == 2) {
		if (studentCount != 0) {
			int choice = pickStudent(),
				choice1;
			cout << "Яку їжу ви б хотiли придбати ?" << endl;
			showFood();
			cin >> choice1;
			choice1--;
			students[choice].setMoney(getMoney() - price[choice1]);
			cout << food[choice1] << " продано !" << endl <<
				"Залишок грошей: " << students[choice].getMoney() << endl;
		}
		else
			cout << "Тут немає учнiв !" << endl;
	}
}

void Canteen::showFood() {
	setlocale(LC_CTYPE, "ukr");
	cout << "Доступна їда в їдальнi" << endl;
	for (int i = 0; i < food.size(); i++) {
		cout << i + 1 << ": " << food[i] << " - " << price[i] << "$" << endl;
	}
}

Canteen::~Canteen(){}
