#pragma once
#include<clocale>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include "School.h"
#include <iostream>
using namespace std;

class Menu : virtual public School {
public:

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // used for goto
	COORD CursorPosition; // used for goto

	void gotoXY(int x, int y){
		CursorPosition.X = x;
		CursorPosition.Y = y;
		SetConsoleCursorPosition(console, CursorPosition);
	}

	int cleanConsole(int x) {
		getchar();
		system("CLS");
		gotoXY(0, 1);
		cout << "->";
		gotoXY(0, 1);
		return 1;
	}

	void teacherMenu(School & obj) {
		system("CLS");
		int menu_item = 0, run, x = 1;
		bool running = true;

		gotoXY(0, 1); cout << "->";

		while (running){
			setlocale(LC_CTYPE, "ukr");
			gotoXY(2, 0); cout << "���� ������i�";
			gotoXY(2, 1);  cout << "1) �������� ������i�";
			gotoXY(2, 2);  cout << "2) ������� ������i�";
			gotoXY(2, 3);  cout << "3) ��i������ ������i�";
			gotoXY(2, 4); cout << "������� �i�����";

			system("pause>nul"); // the >nul bit causes it the print no message

			if (GetAsyncKeyState(VK_DOWN) && x != 11 && x >= 0) //down button pressed
			{
				gotoXY(0, x); cout << "  ";
				x++;
				if (x > 4) {
					x--;
					gotoXY(0, x); cout << "->";
				}
				else {
					gotoXY(0, x); cout << "->";
					menu_item++;
				}
				continue;
			}

			if (GetAsyncKeyState(VK_UP) && x != 7) //up button pressed 
			{
				gotoXY(0, x); cout << "  ";
				x--;

				if (x < 1) {
					x++;
					gotoXY(0, x); cout << "->";
				}
				else {
					gotoXY(0, x); cout << "->";
					menu_item--;
				}
				continue;
			}

			if (GetAsyncKeyState(VK_RETURN)) { // Enter key pressed

				switch (menu_item) {

				case 0: {

					gotoXY(0, 7);
					obj.showTeacher();
					cleanConsole(x);
					x = 1;
					menu_item = 0;
					break;
				}


				case 1: {
					gotoXY(0, 7);
					obj.addTeacher();	
					cleanConsole(x);
					x = 1;
					menu_item = 0;
					break;
				}

				case 2: {
					gotoXY(0, 7);
					//obj.deleteTeacher();
					cleanConsole(x);
					x = 1;
					menu_item = 0;
					break;
				}

				case 3: {
					running = false;
					system("CLS");
				}
				}
			}
		}
	}

	void studentMenu(School & obj) {
		system("CLS");
		int menu_item = 0, run, x = 1;
		bool running = true;

		gotoXY(0, 1); cout << "->";

		while (running) {
			setlocale(LC_CTYPE, "ukr");
			gotoXY(2, 0); cout << "���� ���i�";
			gotoXY(2, 1);  cout << "1) �������� ���i�";
			gotoXY(2, 2);  cout << "2) ������ ���i�";
			gotoXY(2, 3);  cout << "3)�������� ���i�";
			gotoXY(2, 4); cout << "������� �i�����";

			system("pause>nul"); // the >nul bit causes it the print no message

			if (GetAsyncKeyState(VK_DOWN) && x != 11 && x >= 0) //down button pressed
			{
				gotoXY(0, x); cout << "  ";
				x++;
				if (x > 4) {
					x--;
					gotoXY(0, x); cout << "->";
				}
				else {
					gotoXY(0, x); cout << "->";
					menu_item++;
				}
				continue;
			}

			if (GetAsyncKeyState(VK_UP) && x != 7) //up button pressed 
			{
				gotoXY(0, x); cout << "  ";
				x--;

				if (x < 1) {
					x++;
					gotoXY(0, x); cout << "->";
				}
				else {
					gotoXY(0, x); cout << "->";
					menu_item--;
				}
				continue;
			}

			if (GetAsyncKeyState(VK_RETURN)) { // Enter key pressed

				switch (menu_item) {

				case 0: {

					gotoXY(0, 7);
					obj.showStudents();
					cleanConsole(x);
					x = 1;
					menu_item = 0;
					break;
				}


				case 1: {
					gotoXY(0, 7);
					obj.addStudent();
					cleanConsole(x);
					x = 1;
					menu_item = 0;
					break;
				}

				case 2: {
					gotoXY(0, 7);
					//obj.deleteStudent();
					cleanConsole(x);
					x = 1;
					menu_item = 0;
					break;
				}

				case 3: {
					running = false;
					system("CLS");
				}
				}
			}
		}
	}

	void canteenMenu(School & obj) {
		system("CLS");
		int menu_item = 0, run, x = 1;
		bool running = true;

		gotoXY(0, 1); cout << "->";

		while (running)
		{
			setlocale(LC_CTYPE, "ukr");
			gotoXY(2, 0); cout << "���� ������i";
			gotoXY(2, 1);  cout << "1) �������� ���";
			gotoXY(2, 2);  cout << "2) ����� ���";
			gotoXY(2, 3);  cout << "3) �������";
			gotoXY(2, 4); cout << "������� �i�����";

			system("pause>nul"); // the >nul bit causes it the print no message

			if (GetAsyncKeyState(VK_DOWN) && x != 11 && x >= 0) //down button pressed
			{
				gotoXY(0, x); cout << "  ";
				x++;
				if (x > 4) {
					x--;
					gotoXY(0, x); cout << "->";
				}
				else {
					gotoXY(0, x); cout << "->";
					menu_item++;
				}
				continue;

			}

			if (GetAsyncKeyState(VK_UP) && x != 7) //up button pressed 
			{
				gotoXY(0, x); cout << "  ";
				x--;

				if (x < 1) {
					x++;
					gotoXY(0, x); cout << "->";
				}
				else {
					gotoXY(0, x); cout << "->";
					menu_item--;
				}
				continue;
			}

			if (GetAsyncKeyState(VK_RETURN)) { // Enter key pressed

				switch (menu_item) {

				case 0: {

					gotoXY(0, 7);
					obj.showFood();
					cleanConsole(x);
					x = 1;
					menu_item = 0;
					break;
				}


				case 1: {
					gotoXY(0, 7);
					obj.addFood();
					cleanConsole(x);
					x = 1;
					menu_item = 0;
					break;
				}

				case 2: {
					gotoXY(0, 7);
					obj.sellFood();
					x = 1;
					menu_item = 0;
					break;
				}

				case 3: {
					running = false;
					system("CLS");
				}
				}
			}
		}
	}

	void lessonMenu(School & obj) {
		system("CLS");
		int menu_item = 0, run, x = 1;
		bool running = true;

		gotoXY(0, 1); cout << "->";

		while (running)
		{
			setlocale(LC_CTYPE, "ukr");
			gotoXY(2, 0); cout << "���� �����i�";
			gotoXY(2, 1);  cout << "1)�������� �����";
			gotoXY(2, 2);  cout << "2) �i��� �� ����";
			gotoXY(2, 3); cout << "������� �i� ����";

			system("pause>nul"); // the >nul bit causes it the print no message

			if (GetAsyncKeyState(VK_DOWN) && x != 11 && x >= 0) //down button pressed
			{
				gotoXY(0, x); cout << "  ";
				x++;
				if (x > 3) {
					x--;
					gotoXY(0, x); cout << "->";
				}
				else {
					gotoXY(0, x); cout << "->";
					menu_item++;
				}
				continue;

			}

			if (GetAsyncKeyState(VK_UP) && x != 7) //up button pressed 
			{
				gotoXY(0, x); cout << "  ";
				x--;

				if (x < 1) {
					x++;
					gotoXY(0, x); cout << "->";
				}
				else {
					gotoXY(0, x); cout << "->";
					menu_item--;
				}
				continue;
			}

			if (GetAsyncKeyState(VK_RETURN)) { // Enter key pressed

				switch (menu_item) {

				case 0: {

					gotoXY(0, 7);
					obj.showLessons();
					cleanConsole(x);
					x = 1;
					menu_item = 0;
					break;
				}


				case 1: {
					gotoXY(0, 7);
					obj.takeLesson();
					cleanConsole(x);
					x = 1;
					menu_item = 0;
					break;
				}

				case 2: {
					running = false;
					system("CLS");
				}
				}
			}
		}
	}

	int run()
	{
		School obj;
		int menu_item = 0, run, x = 1;
		bool running = true;

		gotoXY(0, 1); cout << "->";

		while (running)
		{
			setlocale(LC_CTYPE, "ukr");
			//gotoXY(0, 1); cout << "->";
			gotoXY(2, 0);  cout << "������� ����";
			gotoXY(2, 1);  cout << "1) ��� �����";
			gotoXY(2, 2);  cout << "2) �����";
			gotoXY(2, 3);  cout << "3) ������i";
			gotoXY(2, 4);  cout << "4) ������i";
			gotoXY(2, 5);  cout << "5) �������"; 
			gotoXY(2, 6);  cout << "�����";



			system("pause>nul"); // the >nul bit causes it the print no message

			if (GetAsyncKeyState(VK_DOWN) && x != 11 && x >= 0) //down button pressed
			{
				gotoXY(0, x); cout << "  ";
				x++;
				if (x > 6) {
					x--;
					gotoXY(0, x); cout << "->";
				}
				else {
					gotoXY(0, x); cout << "->";
					menu_item++;
				}
				continue;

			}

			if (GetAsyncKeyState(VK_UP) && x != 7) //up button pressed 
			{
				gotoXY(0, x); cout << "  ";
				x--;

				if (x < 1) {
					x++;
					gotoXY(0, x); cout << "->";
				}
				else {
					gotoXY(0, x); cout << "->";
					menu_item--;
				}
				continue;
			}

			if (GetAsyncKeyState(VK_RETURN)) { // Enter key pressed

				switch (menu_item) {

				case 0: {

					gotoXY(0, 7);
					obj.showSchool();
					cleanConsole(x);
					x = 1;
					menu_item = 0;
					break;
				}


				case 1: {
					gotoXY(0, 7);
					lessonMenu(obj);
					x = 1;
					menu_item = 0;
					gotoXY(0, 1); cout << "->";
					break;
				}

				case 2: {
					gotoXY(0, 7);
					teacherMenu(obj);
					x = 1;
					menu_item = 0;
					gotoXY(0, 1); cout << "->";
					break;
				}

				case 3: {
					gotoXY(0, 7);
					studentMenu(obj);
					cleanConsole(x);
					x = 1;
					menu_item = 0;
					break;
				}

				case 4: {
					gotoXY(0, 7);
					canteenMenu(obj);
					cleanConsole(x);
					x = 1;
					menu_item = 0;
					break;
				}

				case 5: {
					running = false;
				}
				}
			}
		}
		return 0;
	}
};