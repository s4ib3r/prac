#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include "Student.h"
#include <cstdio>
#include <stdio.h>
using namespace std;

class EditData
{
public:
	Student* pt = new Student;
	void scan() // ������� ����� readRecords, editRecords
	{
		pt->scanStudentInfo(); // readRecords
		pt->EditStudentInfo(); // editRecords
	}
	void EditName(int i) // ������. ���
	{
		cout << "|--------------------|\n";
		cout << "|        ���         |\n";
		cout << "|--------------------|\n";
		cout << "| ";
		cout.width(18); cout << left << pt->readRecords[i].Name;
		cout << " |" << endl;
		cout << "|--------------------|\n" << endl;
		cout << "������� ����� ���\n";
		cout << "> ";
		cin >> pt->editRecords[i].Name;
	}
	void EditSurname(int i) // ������. �������
	{
		cout << "|--------------------|\n";
		cout << "|      �������       |\n";
		cout << "|--------------------|\n";
		cout << "| ";
		cout.width(18); cout << left << pt->readRecords[i].Surname;
		cout << " |" << endl;
		cout << "|--------------------|\n" << endl;
		cout << "������� ����� �������\n";
		cout << "> ";
		cin >> pt->editRecords[i].Surname;
	}
	void EditMidname(int i) // ������. ��������
	{
		cout << "|--------------------|\n";
		cout << "|      ��������      |\n";
		cout << "|--------------------|\n";
		cout << "| ";
		cout.width(18); cout << left << pt->readRecords[i].Midname;
		cout << " |" << endl;
		cout << "|--------------------|\n" << endl;
		cout << "������� ����� ��������\n";
		cout << "> ";
		cin >> pt->editRecords[i].Midname;
	}
	void EditBDay(int i) // ������. ���� ���� ��������
	{
		cout << "|--------------------|\n";
		cout << "|    ���� ��������   |\n";
		cout << "|--------------------|\n";
		cout << "| ";
		cout.width(18); cout << left << pt->readRecords[i].studentDate.day;
		cout << " |" << endl;;
		cout << "|--------------------|\n" << endl;
		cout << "������� ����� ����\n";
		int lock_5 = 1;
		while (lock_5 != 0)
		{
			cout << "> ";
			cin >> pt->editRecords[i].studentDate.day;
			if (pt->editRecords[i].studentDate.day > 31 || pt->editRecords[i].studentDate.day <= 0)
				cout << "������ ����� ��� ���� ��������! ��������� ����\n";
			else lock_5 = 0;
		}
	}
	void EditBMonth(int i) // ������. ����� ���� ��������
	{
		cout << "|--------------------|\n";
		cout << "|   ����� ��������   |\n";
		cout << "|--------------------|\n";
		cout << "| ";
		cout.width(18); cout << left << pt->readRecords[i].studentDate.month;
		cout << " |" << endl;;
		cout << "|--------------------|\n" << endl;
		cout << "������� ����� �����\n";
		int lock_6 = 1;
		while (lock_6 != 0)
		{
			cout << "> ";
			cin >> pt->editRecords[i].studentDate.month;
			if (pt->editRecords[i].studentDate.month > 12 || pt->editRecords[i].studentDate.month <= 0)
				cout << "������ ����� ������ ���� ��������! ��������� ����\n";
			else lock_6 = 0;
		}
	}
	void EditBYear(int i) // ������. ��� ���� ��������
	{
		cout << "|--------------------|\n";
		cout << "|   ��� ��������     |\n";
		cout << "|--------------------|\n";
		cout << "| ";
		cout.width(18); cout << left << pt->readRecords[i].studentDate.year;
		cout << " |" << endl;
		cout << "|--------------------|\n" << endl;
		cout << "������� ����� ���\n";
		int lock_7 = 1;
		while (lock_7 != 0)
		{
			cout << "> ";
			cin >> pt->editRecords[i].studentDate.year;
			if (pt->editRecords[i].studentDate.year > 2023 || pt->editRecords[i].studentDate.year < 1936)
				cout << "������ ����� ������ ���� ��������! ��������� ����\n";
			else lock_7 = 0;
		}
	}
	void EditstartYear(int i) // ������. ��� ������ ��������
	{
		cout << "|---------------------|\n";
		cout << "| ��� ������ �������� |\n";
		cout << "|---------------------|\n";
		cout << "| ";
		cout.width(19); cout << left << pt->readRecords[i].startYear;
		cout << " |" << endl;
		cout << "|---------------------|\n" << endl;
		cout << "������� ����� ��� ������ ��������\n";
		cout << "> ";
		cin >> pt->editRecords[i].startYear;
	}
	void EditInstitute(int i) // ������. ��������
	{
		cout << "|--------------------|\n";
		cout << "|      ��������      |\n";
		cout << "|--------------------|\n";
		cout << "| ";
		cout.width(18); cout << left << pt->readRecords[i].Institute;
		cout << " |" << endl;
		cout << "|--------------------|\n" << endl;
		cout << "������� ������������ ������ ���������\n";
		cout << "> ";
		cin.ignore();
		cin.getline(pt->editRecords[i].Institute, 10);
	}
	void EditDepartment(int i) // ������. �������
	{
		cout << "|------------------------------------------------------------|\n";
		cout << "|                         �������                            |\n";
		cout << "| ";
		cout.width(58); cout << left << pt->readRecords[i].Department;
		cout << " |" << endl;
		cout << "|------------------------------------------------------------|\n" << endl;
		cout << "������� �������� ����� �������\n";
		cout << "> ";
		cin.ignore();
		cin.getline(pt->editRecords[i].Department, 50);
	}
	void EditGroup(int i) // ������. ������
	{
		cout << "|--------------------|\n";
		cout << "|       ������       |\n";
		cout << "|--------------------|\n";
		cout << "| ";
		cout.width(18); cout << left << pt->readRecords[i].Group;
		cout << " |" << endl;
		cout << "|--------------------|\n" << endl;
		cout << "������� �������� ����� ������(����� ����)\n";
		cout << "> ";
		cin >> pt->editRecords[i].Group;
	}
	void EditGradeBook_Number(int i) // ������. ����� �������
	{
		cout << "|--------------------|\n";
		cout << "|   ����� �������    |\n";
		cout << "|--------------------|\n";
		cout << "| ";
		cout.width(18); cout << left << pt->readRecords[i].GradeBook_Number;
		cout << " |" << endl;
		cout << "|--------------------|\n" << endl;
		cout << "������� ����� ����� �������\n";
		cout << "> ";
		cin >> pt->editRecords[i].GradeBook_Number;
	}
	void EditSex(int i) // ������. ���
	{
		cout << "|--------------------|\n";
		cout << "|         ���        |\n";
		cout << "|--------------------|\n";
		if (pt->readRecords[i].Sex == sex::Women) cout << "|      �������       |\n";
		if (pt->readRecords[i].Sex == sex::Men) cout << "|      �������       |\n";
		if (pt->readRecords[i].Sex == sex::Any) cout << "|    �� ��������    |\n";
		cout << "|--------------------|\n" << endl;
		int lock_2 = 0;
		while (lock_2 != 1)
		{
			cout << "�������� ���\n";
			cout << "0. �������\n";
			cout << "1. �������\n";
			cout << "2. �� ��������\n";
			cout << "> ";
			int l;
			cin >> l;
			if (l == 0 || l == 1 || l == 2)
			{
				lock_2 = 1;
				if (l == 0) pt->editRecords[i].Sex = sex::Women;
				if (l == 1) pt->editRecords[i].Sex = sex::Men;
				if (l == 2) pt->editRecords[i].Sex = sex::Any;
			}
			else
			{
				cout << "������ ����� ���� ��������! ��������� ����\n";
			}
		}
	}
	void EditGrade(int i, int k, int j) // ������. ������������
	{
		int g = 0;
		const char* Subjects[10] = { "������", "��", "���.������", "�����������", "�������", "�������", "���������", "��������", "���.�������", "����������" };
		cout << "|------------------+---------------|\n";
		cout << "| �������          |     ������    |\n";
		cout << "|------------------+---------------|\n";
		cout << "| ";
		cout.width(16); cout << left << Subjects[j];
		cout << " | ";
		cout.width(14); 
		if (pt->readRecords[i].examRecords[k][j].markType == Mark::Fail0) cout << left << "�� �����" << "|\n";
		if (pt->readRecords[i].examRecords[k][j].markType == Mark::Pass1) cout << left << "�����" << "|\n";
		if (pt->readRecords[i].examRecords[k][j].markType == Mark::Bad2) cout << left << "�������." << "|\n";
		if (pt->readRecords[i].examRecords[k][j].markType == Mark::Satisfactory3) cout << left << "�����." << "|\n";
		if (pt->readRecords[i].examRecords[k][j].markType == Mark::Good4) cout << left << "������" << "|\n";
		if (pt->readRecords[i].examRecords[k][j].markType == Mark::Excellent5) cout << left << "�������" << "|\n";
		cout << "|------------------+---------------|\n" << endl << endl;
		cout << "������� ����� ������, ���� �����: 1 - ������� ����, 0 - ������� �������\n";
		int lock = 1;
		while (lock != 0)
		{
			cout << ">";
			cin >> g;
			if (g < 0 || g > 5) cout << "������ ����� ������! ��������� ����.\n";
			else lock = 0;
		}
		if (g == 0) pt->editRecords[i].examRecords[k][j].markType = Mark::Fail0;
		if (g == 1) pt->editRecords[i].examRecords[k][j].markType = Mark::Pass1;
		if (g == 2) pt->editRecords[i].examRecords[k][j].markType = Mark::Bad2;
		if (g == 3) pt->editRecords[i].examRecords[k][j].markType = Mark::Satisfactory3;
		if (g == 4) pt->editRecords[i].examRecords[k][j].markType = Mark::Good4;
		if (g == 5) pt->editRecords[i].examRecords[k][j].markType = Mark::Excellent5;
	}
	void DeleteStudent(int k) // ������� �������� �������� �� �������
	{
		for (long i = k; i < pt->def; ++i)
		{
			pt->editRecords[i] = pt->readRecords[i + 1];
		}
		--pt->def;
		ReWrite2File();
	}

	void ReWrite2File() // ������� ���������� � ����
	{
		FILE* TextFile;
		const char* Subjects[10] = { "������", "��", "���.������", "�����������", "�������", "�������", "���������", "��������", "���.�������", "����������" };
		fopen_s(&TextFile, "Markoch.txt", "w");
		for (int i = 0; i <= pt->def - 1; i++)
		{
			fprintf(TextFile, "%s %s %s %d.%d.%d %d %s\n%s\n%s %s %d\n", \
				pt->editRecords[i].Surname, pt->editRecords[i].Name, pt->editRecords[i].Midname, \
				pt->editRecords[i].studentDate.day, pt->editRecords[i].studentDate.month, pt->editRecords[i].studentDate.year, \
				pt->editRecords[i].startYear, pt->editRecords[i].Institute, pt->editRecords[i].Department, \
				pt->editRecords[i].Group, pt->editRecords[i].GradeBook_Number, pt->editRecords[i].Sex);
			int tmp[4][10] = {};
			for (int k = 0; k < 4; k++)
				for (int j = 0; j < 10; j++)
				{
					if (pt->editRecords[i].examRecords[k][j].markType == Mark::Fail0) tmp[k][j] = 0;
					if (pt->editRecords[i].examRecords[k][j].markType == Mark::Pass1) tmp[k][j] = 1;
					if (pt->editRecords[i].examRecords[k][j].markType == Mark::Bad2) tmp[k][j] = 2;
					if (pt->editRecords[i].examRecords[k][j].markType == Mark::Satisfactory3) tmp[k][j] = 3;
					if (pt->editRecords[i].examRecords[k][j].markType == Mark::Good4) tmp[k][j] = 4;
					if (pt->editRecords[i].examRecords[k][j].markType == Mark::Excellent5) tmp[k][j] = 5;
					fprintf(TextFile, "%s %d\n", Subjects[j], tmp[k][j]);
				}
		}
		fclose(TextFile);
	}
};

