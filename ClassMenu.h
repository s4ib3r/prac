#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include <stdio.h>
#include "Student.h"
#include "EditData.h"
#include "Class_Mission.h"

using namespace std;

class ClassMenu
{
public:
    int iMenu = -1;
    int j1 = 0;
    int k1 = 0;
    int k2 = 0;
    Student* st = new Student();
    EditData* ed = new EditData();
    Class_Mission* op = new Class_Mission();
    int menu()
    {
        string sMenu;
        for (; iMenu != 0;)
        {
            system("cls");
            cout << "|-------------------------------------------------|\n";
            cout << "|                  ������� ����.                  |\n";
            cout << "|-------------------------------------------------|\n";
            cout << "|                     0.�����                     |\n";
            cout << "|        1.���������� ���������� � ���������      |\n";
            cout << "|            2.�������� ������ ��������           |\n";
            cout << "|            3.������� �������� �� ������         |\n";
            cout << "|   4.����������/�������� ���������� � ��������   |\n";
            cout << "|          5.������� ������� �� ��������          |\n";
            cout << "|                    6.����������                 |\n";
            cout << "|-------------------------------------------------|\n";
            cout << endl << endl;
            cout << "> ";
            cin >> sMenu;

            iMenu = stoi(sMenu);

            switch (iMenu)
            {
            case 0: return 0;
            case 1: st->scanStudentInfo(); st->printInfo(); system("pause"); break; // ����� Student.h ������� ����� � ������ ����������
            case 2:  st->addStudent(); system("pause"); break; // ����� Student.h ������� ���������� ��������
            case 3: Delete_Number(); system("pause"); break; // ������� ����� ������ �������� � ��� ��������
            case 4:  ChoiseStudent(); system("pause"); break; //������� ����� ������ �������� � ��� ��������(�� ��� ��������� ��� ������)
            case 5:  display_list();  system("pause"); break; //���� ���� ��������� � ��������
            case 6:  information();  system("pause"); break; // ����������
            default: cout << "������ ����� \n"; system("pause"); break;
            }
        }
        return 0;
    }
    void Delete_Number() // ������� �������� ������ �������� ��� ��������
    {
        st->scanStudentInfo(); // ������ readRecords
        st->PrintShortInfo(); // ����� ���� �� ����������
        int edMenu;
        string eMenu;
        int lock_4 = 1;
        int j = 0;
        cout << endl << endl;
        while (lock_4 != 0)
        {
            cout << "> ";
            cin >> eMenu;
            edMenu = stoi(eMenu);
            if (edMenu > st->def || edMenu < 0)
            {
                cout << "������ ����� ������! ��������� ����.\n";
                Delete_Number(); // ������� � ������
            }
            if (edMenu == 0)
            {
                lock_4 = 0;
                menu();
            }
            else
            {
                j = edMenu-1;
                lock_4 = 0;
                ed->scan(); //����� EditData.h ���������� readRecords � editRecords
                ed->DeleteStudent(j); //����� EditData.h ������� �������� ��������
            }
        }
    }
    void information() // ������� ������ ����������
    {
        system("cls");
        cout << endl << endl;
        cout << "�������� ������ �������� ������� ������ ��������, ������ ����-04-22\n" << endl;
        cout << "� ������ ������������:\n";
        cout << "   ������(� Class_Mission.h)\n";
        cout << "   ������:\n";
        cout << "          Class_Mission.h(����� � ����������� ��������������� ������� �� ��������)\n";
        cout << "          ClassMenu.h(���� ���� ���������)\n";
        cout << "          EditData.h(����� ������� � ���������� ����������, ������� ����������)\n";
        cout << "          Student.h(�������� �����, ��� ��������� ���������, ������� ���������� � ����� � ������� ������)\n";
        cout << "   ������������ ���� Markoch.txt\n" << endl;
        cout << "������� ������� �� ������ �������: 36\n";
        cout << "��� ������������� �����: ���������(6 �������)\n" << endl << endl;
        cout << "��� �������� � �� ������ ��������� � �� ����� ��������� ��������!\n" << endl << endl;
    }
    void display_list() // ������� ������ ��������������� �������
    {
        cout << endl << endl << endl;
        int lock = 1;
        while (lock != 0)
        {
            system("cls");
            cout << "�������� ������� ������ �������� ���������\n";
            cout << "0.�����\n";
            cout << "1.������ �������� �������� ����\n";
            cout << "2.������ �������� �������� ����\n";
            cout << "3.������� ���� ���������\n";
            cout << endl;
            cout << "> ";
            int k4 = 0;
            int ex;
            string e;
            cin >> e;
            ex = stoi(e);
            k4 = ex;
            if (k4 == 0)
            {
                lock = 0;
                menu(); system("pause"); break; // ����� � ������� ����
            }
            if (k4 > 3)
                cout << "������ �����! ��������� ����\n";
            if (k4 == 1 || k4 == 2 || k4 == 3)
            {
                lock = 0;
                op->Zadanie(k4);
            }
        }
    }
    void ChoiseStudent() // ������� ������ �������� ��� �������������� � �������� ��������� ������
    {
        st->scanStudentInfo();
        st->PrintShortInfo();
        int edMenu;
        string eMenu;
        int lock_4 = 1;
        cout << endl << endl;
        while (lock_4 != 0)
        {
            cout << "> ";
            cin >> eMenu;
            edMenu = stoi(eMenu);
            if (edMenu > st->def  || edMenu < 0)
            {
                cout << "������ ����� ������! ��������� ����.\n";
            }
            if (edMenu == 0)
            {
                lock_4 = 0;
                menu();
            }
            else
            {
                lock_4 = 0;
                editMenu();
                j1 = edMenu;
            }
        }
    }
    int editMenu() //������� ���� �������������� ����������
    {
        int edMenu = -1;
        string eMenu;
        for (; edMenu != 0;)
        {
            system("cls");
            cout << "|--------------------------------------------------|\n";
            cout << "|       ���� �������������� ��������               |\n";
            cout << "|--------------------------------------------------|\n";
            cout << "|     0. �����                                     |\n";
            cout << "|     1. �������� ���                              |\n";
            cout << "|     2. �������� ���� ��������                    |\n";
            cout << "|     3. �������� ��������                         |\n";
            cout << "|     4. �������� �������                          |\n";
            cout << "|     5. �������� ������                           |\n";
            cout << "|     6. �������� ����� �������                    |\n";
            cout << "|     7. �������� ���                              |\n";
            cout << "|     8. �������� ������������                     |\n";
            cout << "|--------------------------------------------------|\n";
            cout << endl << endl;
            cout << "> ";
            cin >> eMenu;

            edMenu = stoi(eMenu);

            switch (edMenu)
            {
            case 0: menu(); system("pause"); break;
            case 1: editFIO(); system("pause"); break;
            case 2: editDate(); system("pause"); break;
            case 3: ed->scan(); ed->EditInstitute(j1); ed->ReWrite2File(); system("pause"); break;
            case 4: ed->scan(); ed->EditDepartment(j1); ed->ReWrite2File(); system("pause"); break;
            case 5: ed->scan(); ed->EditGroup(j1); ed->ReWrite2File(); system("pause"); break;
            case 6: ed->scan(); ed->EditGradeBook_Number(j1); ed->ReWrite2File(); system("pause"); break;
            case 7: ed->scan(); ed->EditSex(j1); ed->ReWrite2File();  system("pause"); break;
            case 8: editGrade(); system("pause"); break;
            default: cout << "������ ����� \n"; system("pause"); break;
            }
        }
        return menu();
    }
    int editFIO() // ����� �������������� ���
    {
        int edMenu = -1;
        string eMenu;
        for (; edMenu != 0;)
        {
            system("cls");
            cout << "|--------------------------------------------------|\n";
            cout << "|       ���� �������������� ��������               |\n";
            cout << "|--------------------------------------------------|\n";
            cout << "|     0. �����                                     |\n";
            cout << "|     1. �������� �������                          |\n";
            cout << "|     2. �������� ���                              |\n";
            cout << "|     3. �������� ��������                         |\n";
            cout << "|--------------------------------------------------|\n";
            cout << endl << endl;
            cout << "> ";
            cin >> eMenu;

            edMenu = stoi(eMenu);

            switch (edMenu)
            {
            case 0: menu(); system("pause"); break;
            case 1: ed->scan(); ed->EditSurname(j1); ed->ReWrite2File(); system("pause"); break;
            case 2: ed->scan(); ed->EditName(j1); ed->ReWrite2File(); system("pause"); break;
            case 3: ed->scan(); ed->EditMidname(j1); ed->ReWrite2File(); system("pause"); break;
            default: cout << "������ ����� \n"; system("pause"); break;
            }
        }
        return menu();
    }
    int editDate() // ����� �������������� ���� ��������
    {
        int edMenu = -1;
        string eMenu;
        for (; edMenu != 0;)
        {
            system("cls");
            cout << "|--------------------------------------------------|\n";
            cout << "| ���� �������������� ���� �������� ��������       |\n";
            cout << "|--------------------------------------------------|\n";
            cout << "|     0. �����                                     |\n";
            cout << "|     1. �������� ����                             |\n";
            cout << "|     2. �������� �����                            |\n";
            cout << "|     3. �������� ���                              |\n";
            cout << "|--------------------------------------------------|\n";
            cout << endl << endl;
            cout << "> ";
            cin >> eMenu;

            edMenu = stoi(eMenu);

            switch (edMenu)
            {
            case 0: menu(); system("pause"); break;
            case 1: ed->scan(); ed->EditBDay(j1); ed->ReWrite2File(); system("pause"); break;
            case 2: ed->scan(); ed->EditBMonth(j1); ed->ReWrite2File(); system("pause"); break;
            case 3: ed->scan(); ed->EditBYear(j1); ed->ReWrite2File(); system("pause"); break;
            default: cout << "������ ����� \n"; system("pause"); break;
            }
        }
        return menu();
    }
    int editGrade() //�������������� ������������: ����� ��������
    {
        int edMenu = -1;
        string eMenu;
        for (; edMenu != 0;)
        {
            system("cls");
            cout << "|--------------------------------------------------|\n";
            cout << "| ���� �������������� ������������ ��������        |\n";
            cout << "|--------------------------------------------------|\n";
            cout << "|   0. �����                                       |\n";
            cout << "|   1. �������� ������ �� 1 �������                |\n";
            cout << "|   2. �������� ������ �� 2 �������                |\n";
            cout << "|   3. �������� ������ �� 3 �������                |\n";
            cout << "|   4. �������� ������ �� 4 �������                |\n";
            cout << "|--------------------------------------------------|\n";
            cout << endl << endl;
            cout << "> ";
            cin >> eMenu;
            edMenu = stoi(eMenu);
            k1 = edMenu-1;
            switch (edMenu)
            {
            case 0: menu(); system("pause"); break;
            case 1: editGradeSubject(); system("pause"); break;
            case 2: editGradeSubject(); system("pause"); break;
            case 3: editGradeSubject(); system("pause"); break;
            case 4: editGradeSubject(); system("pause"); break;
            default: cout << "������ ����� \n"; system("pause"); break;
            }
        }
        return menu();
    }
    void editGradeSubject() //�������������� ������������: ����� ��������
    {
        int ex = -1;
        string eMenu;
        for (; ex != 0;)
        {
            system("cls");
            cout << "|--------------------------------------------------|\n";
            cout << "| ���� �������������� ������������ ��������        |\n";
            cout << "|--------------------------------------------------|\n";
            cout << "| 0. �����                                         |\n";
            cout << "| 1. �������� ������ �� ������                     |\n";
            cout << "| 2. �������� ������ �� ��                         |\n";
            cout << "| 3. �������� ������ �� ���.������                 |\n";
            cout << "| 4. �������� ������ �� �����������                |\n";
            cout << "| 5. �������� ������ �� �������                    |\n";
            cout << "| 6. �������� ������ �� �������                    |\n";
            cout << "| 7. �������� ������ �� ���������                  |\n";
            cout << "| 8. �������� ������ �� ��������                   |\n";
            cout << "| 9. �������� ������ �� ���.�������                |\n";
            cout << "| 10. �������� ������ �� ����������                |\n";
            cout << "|--------------------------------------------------|\n";
            cout << endl << endl;
            cout << "> ";
            cin >> eMenu;

            ex = stoi(eMenu);
            k2 = ex-1;
            switch (ex)
            {
            case 0: menu(); system("pause"); break;
            case 1: ed->scan(); ed->EditGrade(j1, k1, k2); ed->ReWrite2File(); system("pause"); break;
            case 2: ed->scan(); ed->EditGrade(j1, k1, k2); ed->ReWrite2File(); system("pause"); break;
            case 3: ed->scan(); ed->EditGrade(j1, k1, k2); ed->ReWrite2File(); system("pause"); break;
            case 4: ed->scan(); ed->EditGrade(j1, k1, k2); ed->ReWrite2File(); system("pause"); break;
            case 5: ed->scan(); ed->EditGrade(j1, k1, k2); ed->ReWrite2File(); system("pause"); break;
            case 6: ed->scan(); ed->EditGrade(j1, k1, k2); ed->ReWrite2File(); system("pause"); break;
            case 7: ed->scan(); ed->EditGrade(j1, k1, k2); ed->ReWrite2File(); system("pause"); break;
            case 8: ed->scan(); ed->EditGrade(j1, k1, k2); ed->ReWrite2File(); system("pause"); break;
            case 9: ed->scan(); ed->EditGrade(j1, k1, k2); ed->ReWrite2File(); system("pause"); break;
            case 10: ed->scan(); ed->EditGrade(j1, k1, k2); ed->ReWrite2File(); system("pause"); break;
            default: cout << "������ ����� \n"; system("pause"); break;
            }
        }
    }
};