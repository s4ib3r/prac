#include <iostream>
#include <string>
#include <windows.h>
#include <stdio.h>
#include "Student.h"
#include "ClassMenu.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ClassMenu* mainMenu = new ClassMenu();
	mainMenu->menu(); // главное меню
	
	return 0;
}