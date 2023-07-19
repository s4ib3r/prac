#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include <stdio.h>


using namespace std;

enum class sex : unsigned int //����� ���� ���������
{
    Women,
    Men,
    Any
};

enum class Mark :  int //����� ������
{
    Fail0,
    Pass1,
    Bad2,
    Satisfactory3,
    Good4,
    Excellent5
};


struct Exams //��������� ������������
{
    char Subject[30];
    enum class Mark markType;
};

struct birthdate //��������� ���� ��������
{
    unsigned short day;
    unsigned short month;
    unsigned short year;
};

struct StudentNode //������� ���������
{
    char Surname[30];
    char Name[30];
    char Midname[30];
    birthdate studentDate;
    int startYear;
    char Institute[10];
    char Department[50];
    char Group[30];
    char GradeBook_Number[30];
    enum class sex Sex;
    Exams examRecords[4][10];
};


struct Node { //������
    StudentNode data;
    struct Node* next;
};


class Student //����������� �����
{
public:
    struct Node* myHead = NULL;
    struct Node* current;
    StudentNode readRecords[50] = {};
    int i = 0;
    int cItem = 0;
    StudentNode addRecord[40] = {};
    int countItem = -1;
    int def = 0;
    void addItem(StudentNode data) // ������� ���������� ������ ����������
    {
        struct Node* newItem = new Node;
        newItem->data = data;
        if (cItem == 0) {
            newItem->next = NULL;
        }
        else
        {
            newItem->next = myHead;
        }
        myHead = newItem;
        cItem++;
    }
    void deleteItem(int index) // ������� �������� ������ ����� ���������� ������
    {
        if (index >= 0 and index < cItem and cItem>0) {
            struct Node* current = myHead;
            struct Node* old;
            if (index == 0) {
                old = myHead;
                myHead = current->next;
                delete old;
                cItem--;
            }
            else {
                int i = 0;
                while (current) {
                    if (i == index - 1) {
                        old = current->next->next;
                        delete current->next;
                        current->next = old;
                        cItem--;
                        break;
                    }
                    i++;
                    current = current->next;
                }
            }
        }

    }
    void printDate(unsigned short day, unsigned short month, unsigned short year, int wLine)  // ��������� ����
    {
        int w = 10;
        int delta = (wLine - w) / 2 - 1;
        cout << left;
        cout.width(delta); cout << " ";
        if (day > 9) cout << day; else cout << "0" << day;
        cout << ".";
        if (month > 9) cout << month; else cout << "0" << month;
        cout << ".";
        cout << year;
        cout.width(delta); cout << " ";
    }
    void printDate(struct birthdate date1, int wLine) // ��������� ���� �� ��������
    {
        printDate(date1.day, date1.month, date1.year, wLine);
    }

    void printDate(struct birthdate* date2, int wLine)  // ��������� ���� �� ���������
    {
        printDate(date2->day, date2->month, date2->year, wLine);
    }

    void printDate(struct birthdate& date3, unsigned short wLine)  // ��������� ���� �� ������
    {
        printDate(date3.day, date3.month, date3.year, wLine);
    }
    void scanStudentInfo() //������ ���������� �� ����� readRecords
    {
        system("cls");
        FILE* textFile;
        fopen_s(&textFile, "Markoch.txt", "r");
        while (!feof(textFile))
        {
            fscanf_s(textFile, "%s", &readRecords[i].Surname, _countof(readRecords[i].Surname));
            fscanf_s(textFile, "%s", &readRecords[i].Name, _countof(readRecords[i].Name));
            fscanf_s(textFile, "%s", &readRecords[i].Midname, _countof(readRecords[i].Midname));
            fscanf_s(textFile, "%d.%d.%d", &readRecords[i].studentDate.day, &readRecords[i].studentDate.month, &readRecords[i].studentDate.year);
            fscanf_s(textFile, "%d", &readRecords[i].startYear);
            fscanf_s(textFile, "%s\n", &readRecords[i].Institute, _countof(readRecords[i].Institute));
            fgets(readRecords[i].Department, 50, textFile);
            readRecords[i].Department[strlen(readRecords[i].Department) - 1] = 0;
            fscanf_s(textFile, "%s", &readRecords[i].Group, _countof(readRecords[i].Group));
            fscanf_s(textFile, "%s", &readRecords[i].GradeBook_Number, _countof(readRecords[i].GradeBook_Number));
            fscanf_s(textFile, "%d", &readRecords[i].Sex);
            for (int k = 0; k < 4; k++)
            {
                for (int j = 0; j < 10; j++)
                {
                    fscanf_s(textFile, "%s %d", &readRecords[i].examRecords[k][j].Subject, _countof(readRecords[i].examRecords[k][j].Subject), &readRecords[i].examRecords[k][j].markType);
                }
            }
            i++;
            countItem++;
        }
        fclose(textFile);
        i = 0;
        def = countItem;
        countItem = -1;
    }

    StudentNode editRecords[50] = {};
    void EditStudentInfo() //������ ���������� �� ����� editRecords
    {
        int i = 0;
        system("cls");
        FILE* textFile;
        fopen_s(&textFile, "Markoch.txt", "r");
        while (!feof(textFile))
        {
            fscanf_s(textFile, "%s", &editRecords[i].Surname, _countof(editRecords[i].Surname));
            fscanf_s(textFile, "%s", &editRecords[i].Name, _countof(editRecords[i].Name));
            fscanf_s(textFile, "%s", &editRecords[i].Midname, _countof(editRecords[i].Midname));
            fscanf_s(textFile, "%d.%d.%d", &editRecords[i].studentDate.day, &editRecords[i].studentDate.month, &editRecords[i].studentDate.year);
            fscanf_s(textFile, "%d", &editRecords[i].startYear);
            fscanf_s(textFile, "%s\n", &editRecords[i].Institute, _countof(editRecords[i].Institute));
            fgets(editRecords[i].Department, 50, textFile);
            editRecords[i].Department[strlen(editRecords[i].Department) - 1] = 0;
            fscanf_s(textFile, "%s", &editRecords[i].Group, _countof(editRecords[i].Group));
            fscanf_s(textFile, "%s", &editRecords[i].GradeBook_Number, _countof(editRecords[i].GradeBook_Number));
            fscanf_s(textFile, "%d", &editRecords[i].Sex);
            for (int k = 0; k < 4; k++)
            {
                for (int j = 0; j < 10; j++)
                {
                    fscanf_s(textFile, "%s %d", &editRecords[i].examRecords[k][j].Subject, _countof(editRecords[i].examRecords[k][j].Subject), &editRecords[i].examRecords[k][j].markType);
                }
            }
            i++;
        }
        fclose(textFile);
    }

    void PrintShortInfo() //������ ������ ������ ���������
    {
        cout << "|-----------------------------------------------|\n";
        cout << "|   �������� ����� ��������                     |\n";
        cout << "|-----------------------------------------------|\n";
        cout << "| 0. �����                                      |\n";
        for (int i = 0; i < def ; i++)
        {
            if (i >= 9)
            {
                cout << "|" << i + 1 << ". ";
                cout.width(14); cout << left << readRecords[i].Surname;
                cout.width(15); cout << left << readRecords[i].Name;
                cout.width(14); cout << left << readRecords[i].Midname << "|\n";
            }
            else
            {
                cout << "| " << i + 1 << ". ";
                cout.width(14); cout << left << readRecords[i].Surname;
                cout.width(15); cout << left << readRecords[i].Name;
                cout.width(14); cout << left << readRecords[i].Midname << "|\n";
            }
        }
        cout << "|-----------------------------------------------|\n";
    }

    void printInfo() // ������� ������ ���������� ���������
    {
        for (int i = 0; i < def; i++)
        {
            cout << "|----------------------+-----------------------------------------------|\n";
            cout << "| ���                  | ";
            cout.width(16); cout << left << readRecords[i].Surname;
            cout.width(16); cout << left << readRecords[i].Name;
            cout.width(14); cout << left << readRecords[i].Midname << "|\n";
            cout << "| ���� ��������        |";
            printDate(readRecords[i].studentDate, 10);
            cout << "                                   |\n";
            cout << "| ���� �����������     |"; cout << " ";
            cout.width(46); cout << readRecords[i].startYear;
            cout << "|\n";
            cout << "| ��������             |"; cout << " ";
            cout.width(46); cout << readRecords[i].Institute;
            cout << "|\n";
            cout << "| ���������            |"; cout << " ";
            cout.width(46); cout << readRecords[i].Department;
            cout << "|\n";
            cout << "| ������               |"; cout << " ";
            cout.width(46); cout << readRecords[i].Group;
            cout << "|\n";
            cout << "| ����� �������        |"; cout << " ";
            cout.width(46); cout << readRecords[i].GradeBook_Number;
            cout << "|\n";
            if (readRecords[i].Sex == sex::Men) { cout << "| ���                  | �������                                       |\n"; }
            if (readRecords[i].Sex == sex::Women) { cout << "| ���                  | �������                                       |\n"; }
            if (readRecords[i].Sex == sex::Any) { cout << "| ���                  | �� ��������                                  |\n"; }
            cout << "|----------------------+-----------------------------------------------|\n";
            cout << endl;

        }
    }

    int x = 0;

    void addStudent() //������� ���������� ��������
    {
        system("cls");
        cout << "���� ������\n\n";
        cout << "������� ���\n";
        cout << "> ";
        cin >> addRecord[x].Surname >> addRecord[x].Name >> addRecord[x].Midname;
        int lock = 1;
        while (lock == 1)
        {
            cout << "������� ���� ��������(����� ������)\n";
            cout << "> ";
            cin >> addRecord[x].studentDate.day >> addRecord[x].studentDate.month >> addRecord[x].studentDate.year;
            if (addRecord[x].studentDate.day < 0 || addRecord[x].studentDate.day > 31 || addRecord[x].studentDate.month < 0 || addRecord[x].studentDate.month > 12 || addRecord[x].studentDate.year < 1936 || addRecord[x].studentDate.year > 2023)
                cout << "������ � ����! ��������� ����\n";
            else lock = 0;
        }
        cout << "������� ��� ������ ��������\n";
        cout << "> ";
        cin >> addRecord[x].startYear;
        cout << "������� ������������ ���������\n";
        cout << "> ";
        cin >> addRecord[x].Institute;
        cout << "������� �������� �������\n";
        cout << "> ";
        cin.ignore();
        cin.getline(addRecord[x].Department, 50);
        cout << "������� �������� ������\n";
        cout << "> ";
        cin >> addRecord[x].Group;
        cout << "������� ����� �������� ������\n";
        cout << "> ";
        cin >> addRecord[x].GradeBook_Number;
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
                if (l == 0) addRecord[x].Sex = sex::Women;
                if (l == 1) addRecord[x].Sex = sex::Men;
                if (l == 2) addRecord[x].Sex = sex::Any;
            }
            else
            {
                cout << "������ ����� ���� ��������! ��������� ����\n";
            }
        }
        system("cls");
        cout << "���� ������������ ��������\n";
        const char* Subjects[10] = { "������", "��", "���.������", "�����������", "�������", "�������", "���������", "��������", "���.�������", "����������" };
        int tmp[4][10] = {};
        for (int i = 0; i < 10; i++)
        {
            int lock_3 = 1;
            while (lock_3 != 0)
            {
                cout << "������� ������ �� 4 �������� �� �������� " << Subjects[i] << ", ���� �������: 1 - ������� ����, 0 - ������� �������" << endl;
                cout << "> ";
                cin >> tmp[0][i] >> tmp[1][i] >> tmp[2][i] >> tmp[3][i];
                for (int d = 0; d < 4; d++)
                {
                    if (tmp[d][i] < 0 || tmp[d][i] > 5)
                    {
                        cout << "������ ����� ������! ��������� ����.\n";
                        lock_3 = 1;
                    }
                    else lock_3 = 0;
                }
            }
        }
        FILE* TextFile;
        fopen_s(&TextFile, "Markoch.txt", "a+");
        for (int i = 0; i < 1 ; i++) {
            fprintf(TextFile, "%s %s %s %d.%d.%d %d %s\n%s\n%s %s %d\n", \
                addRecord[i].Surname, addRecord[i].Name, addRecord[i].Midname, \
                addRecord[i].studentDate.day, addRecord[i].studentDate.month, addRecord[i].studentDate.year, \
                addRecord[i].startYear, addRecord[i].Institute, addRecord[i].Department, \
                addRecord[i].Group, addRecord[i].GradeBook_Number, addRecord[i].Sex);
            for (int k = 0; k < 4; k++)
                for (int j = 0; j < 10; j++) {
                    fprintf(TextFile, "%s %d\n", Subjects[j], tmp[k][j]);
                }
        }
        fclose(TextFile);
    }
};

