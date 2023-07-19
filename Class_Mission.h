#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include <stdio.h>
#include "Student.h"

using namespace std;

class Class_Mission
{
public:
	Student* xd = new Student;
	void Zadanie(int q) // ������� �� ���� ����-������� � ����������� readRecords � �� ������� ����� ������
	{
		xd->scanStudentInfo();
		int i = 0;
		int c = 0;
		int s = 0;
		for (int o = 0; o < xd->def; o++)
		{
			for (int j = 0; j < xd->def; j++)
			{
				for (int k = 0; k < 4; k++)
				{
					for (int v = 0; v < 10; v++)
					{
						if (xd->readRecords[j].examRecords[k][v].markType == Mark::Excellent5 && k == 1)
							c++;
						if (xd->readRecords[j + 1].examRecords[k][v].markType == Mark::Excellent5 && k == 1)
							s++;
					}
				}
				if (c < s)
				{
					swap(xd->readRecords[j], xd->readRecords[j + 1]);
				}
				c = 0;
				s = 0;
			}
		}
		for (int j = xd->def; j >= 0; j--)
			xd->addItem(xd->readRecords[j]);
		cout << "|------------------------------------------+----------------|\n";
		cout << "| �������� ";
			if (q == 1)
			{
				cout <<     "�������� ����                   | ���-�� ������ |\n";
			}
			if (q == 2)
			{
				cout << "�������� ����                   | ���-�� ������ |\n";
			}
			if (q == 3)
			{
				cout << "������ ����                     | ���-�� ������ |\n";
			}
		cout << "|------------------------------------------+----------------|\n";
		for (xd->current = xd->myHead; xd->current->next != NULL; xd->current = xd->current->next)
		{
			if (xd->current->data.Sex == sex::Women && q == 1)
			{
				cout << "| ";
				cout.width(14); cout << left << xd->current->data.Surname;
				cout.width(13); cout << left << xd->current->data.Name;
				cout.width(14); cout << left << xd->current->data.Midname;
				cout << "|       ";
				int mark = 0;
				for (int k = 0; k < 4; k++)
					for (int v = 0; v < 10; v++)
						if (xd->current->data.examRecords[k][v].markType == Mark::Excellent5 && k == 1)
							mark++;
				cout.width(2);  cout << mark;
				cout << "       |\n";
				mark = 0;
			}
			if (xd->current->data.Sex == sex::Men && q == 2)
			{
				cout << "| ";
				cout.width(14); cout << left << xd->current->data.Surname;
				cout.width(13); cout << left << xd->current->data.Name;
				cout.width(14); cout << left << xd->current->data.Midname;
				cout << "|       ";
				int mark = 0;
				for (int k = 0; k < 4; k++)
					for (int v = 0; v < 10; v++)
						if (xd->current->data.examRecords[k][v].markType == Mark::Excellent5 && k == 1)
							mark++;
				cout.width(2);  cout << mark;
				cout << "       |\n";
				mark = 0;
			}
			if (q == 3)
			{
				cout << "| ";
				cout.width(14); cout << left << xd->current->data.Surname;
				cout.width(13); cout << left << xd->current->data.Name;
				cout.width(14); cout << left << xd->current->data.Midname;
				cout << "|       ";
				int mark = 0;
				for (int k = 0; k < 4; k++)
					for (int v = 0; v < 10; v++)
						if (xd->current->data.examRecords[k][v].markType == Mark::Excellent5 && k == 1)
							mark++;
				cout.width(2);  cout << mark;
				cout << "       |\n";
				mark = 0;
			}
		}
		cout << "|------------------------------------------+----------------|\n";
		struct Node* prev = xd->myHead;

		while (xd->myHead)
		{
			xd->myHead = xd->myHead->next;
			free(prev);
			prev = xd->myHead;
		}
	}
};

