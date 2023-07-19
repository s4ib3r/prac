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
            cout << "|                  Главное меню.                  |\n";
            cout << "|-------------------------------------------------|\n";
            cout << "|                     0.Выход                     |\n";
            cout << "|        1.Отобразить информацию о студентах      |\n";
            cout << "|            2.Добавить нового студента           |\n";
            cout << "|            3.Удалить студента из списка         |\n";
            cout << "|   4.Посмотреть/Изменить информацию о студенте   |\n";
            cout << "|          5.Сделать задание по варианту          |\n";
            cout << "|                    6.Информация                 |\n";
            cout << "|-------------------------------------------------|\n";
            cout << endl << endl;
            cout << "> ";
            cin >> sMenu;

            iMenu = stoi(sMenu);

            switch (iMenu)
            {
            case 0: return 0;
            case 1: st->scanStudentInfo(); st->printInfo(); system("pause"); break; // Класс Student.h функция скана и вывода информации
            case 2:  st->addStudent(); system("pause"); break; // Класс Student.h функция добавления студента
            case 3: Delete_Number(); system("pause"); break; // функция ввода номера студента и его проверки
            case 4:  ChoiseStudent(); system("pause"); break; //функция ввода номера студента и его проверки(но для изменения его данных)
            case 5:  display_list();  system("pause"); break; //ввод пола студентов и проверка
            case 6:  information();  system("pause"); break; // информация
            default: cout << "Ошибка ввода \n"; system("pause"); break;
            }
        }
        return 0;
    }
    void Delete_Number() // функция проверки номера студента для удаления
    {
        st->scanStudentInfo(); // запись readRecords
        st->PrintShortInfo(); // вывод окна со студентами
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
                cout << "Ошибка ввода номера! Повторный ввод.\n";
                Delete_Number(); // возврат в начало
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
                ed->scan(); //Класс EditData.h считывание readRecords и editRecords
                ed->DeleteStudent(j); //Класс EditData.h Функция удаления студента
            }
        }
    }
    void information() // функция вывода информации
    {
        system("cls");
        cout << endl << endl;
        cout << "Курсовую работу выполнил Маркочь Андрей Иванович, группа БАСО-04-22\n" << endl;
        cout << "В работе присутствуют:\n";
        cout << "   списки(в Class_Mission.h)\n";
        cout << "   классы:\n";
        cout << "          Class_Mission.h(класс с выполнением индивидуального задания по варианту)\n";
        cout << "          ClassMenu.h(окна меню программы)\n";
        cout << "          EditData.h(класс функций с изменением информации, функция перезаписи)\n";
        cout << "          Student.h(основной класс, где находится структура, функции считывания с файла и функции вывода)\n";
        cout << "   подключаемый файл Markoch.txt\n" << endl;
        cout << "Вариант задания по номеру зачётки: 36\n";
        cout << "Тип подключаемого файла: текстовый(6 вариант)\n" << endl << endl;
        cout << "Все студенты и их данные вымышлены и не несут смысловой нагрузки!\n" << endl << endl;
    }
    void display_list() // функция вывода индивидуального задания
    {
        cout << endl << endl << endl;
        int lock = 1;
        while (lock != 0)
        {
            system("cls");
            cout << "Выберите условия вывода рейтинга студентов\n";
            cout << "0.Выход\n";
            cout << "1.Только студенты женского пола\n";
            cout << "2.Только студенты мужского пола\n";
            cout << "3.Вывести всех студентов\n";
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
                menu(); system("pause"); break; // выход в главное меню
            }
            if (k4 > 3)
                cout << "Ошибка ввода! Повторный ввод\n";
            if (k4 == 1 || k4 == 2 || k4 == 3)
            {
                lock = 0;
                op->Zadanie(k4);
            }
        }
    }
    void ChoiseStudent() // функция выбора студента для редактирования и проверка введённого номера
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
                cout << "Ошибка ввода номера! Повторный ввод.\n";
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
    int editMenu() //Главное меню редактирования информации
    {
        int edMenu = -1;
        string eMenu;
        for (; edMenu != 0;)
        {
            system("cls");
            cout << "|--------------------------------------------------|\n";
            cout << "|       Меню редактирования студента               |\n";
            cout << "|--------------------------------------------------|\n";
            cout << "|     0. Выход                                     |\n";
            cout << "|     1. Изменить ФИО                              |\n";
            cout << "|     2. Изменить Дату Рождения                    |\n";
            cout << "|     3. Изменить Институт                         |\n";
            cout << "|     4. Изменить кафедру                          |\n";
            cout << "|     5. Изменить группу                           |\n";
            cout << "|     6. Изменить номер зачётки                    |\n";
            cout << "|     7. Изменить пол                              |\n";
            cout << "|     8. Изменить успеваемость                     |\n";
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
            default: cout << "Ошибка ввода \n"; system("pause"); break;
            }
        }
        return menu();
    }
    int editFIO() // выбор редактирования ФИО
    {
        int edMenu = -1;
        string eMenu;
        for (; edMenu != 0;)
        {
            system("cls");
            cout << "|--------------------------------------------------|\n";
            cout << "|       Меню редактирования студента               |\n";
            cout << "|--------------------------------------------------|\n";
            cout << "|     0. Выход                                     |\n";
            cout << "|     1. Изменить Фамилию                          |\n";
            cout << "|     2. Изменить Имя                              |\n";
            cout << "|     3. Изменить Отчество                         |\n";
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
            default: cout << "Ошибка ввода \n"; system("pause"); break;
            }
        }
        return menu();
    }
    int editDate() // выбор редактирования даты рождения
    {
        int edMenu = -1;
        string eMenu;
        for (; edMenu != 0;)
        {
            system("cls");
            cout << "|--------------------------------------------------|\n";
            cout << "| Меню редактирования даты рождения студента       |\n";
            cout << "|--------------------------------------------------|\n";
            cout << "|     0. Выход                                     |\n";
            cout << "|     1. Изменить День                             |\n";
            cout << "|     2. Изменить Месяц                            |\n";
            cout << "|     3. Изменить Год                              |\n";
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
            default: cout << "Ошибка ввода \n"; system("pause"); break;
            }
        }
        return menu();
    }
    int editGrade() //редактирование успеваемости: выбор семестра
    {
        int edMenu = -1;
        string eMenu;
        for (; edMenu != 0;)
        {
            system("cls");
            cout << "|--------------------------------------------------|\n";
            cout << "| Меню редактирования успеваемости студента        |\n";
            cout << "|--------------------------------------------------|\n";
            cout << "|   0. Выход                                       |\n";
            cout << "|   1. Изменить оценку за 1 семестр                |\n";
            cout << "|   2. Изменить оценку за 2 семестр                |\n";
            cout << "|   3. Изменить оценку за 3 семестр                |\n";
            cout << "|   4. Изменить оценку за 4 семестр                |\n";
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
            default: cout << "Ошибка ввода \n"; system("pause"); break;
            }
        }
        return menu();
    }
    void editGradeSubject() //редактирование успеваемости: выбор предмета
    {
        int ex = -1;
        string eMenu;
        for (; ex != 0;)
        {
            system("cls");
            cout << "|--------------------------------------------------|\n";
            cout << "| Меню редактирования успеваемости студента        |\n";
            cout << "|--------------------------------------------------|\n";
            cout << "| 0. Выход                                         |\n";
            cout << "| 1. Изменить оценку за Физику                     |\n";
            cout << "| 2. Изменить оценку за ЯП                         |\n";
            cout << "| 3. Изменить оценку за Мат.анализ                 |\n";
            cout << "| 4. Изменить оценку за Физкультуру                |\n";
            cout << "| 5. Изменить оценку за Историю                    |\n";
            cout << "| 6. Изменить оценку за Русский                    |\n";
            cout << "| 7. Изменить оценку за Экономику                  |\n";
            cout << "| 8. Изменить оценку за Практику                   |\n";
            cout << "| 9. Изменить оценку за Лин.алгебру                |\n";
            cout << "| 10. Изменить оценку за Английский                |\n";
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
            default: cout << "Ошибка ввода \n"; system("pause"); break;
            }
        }
    }
};