#include <iostream>
#include <fstream>
#include <string>
#include "windows.h"

#define random(min, max) min + rand() % (max - min + 1) 
using namespace std;

struct Student {
    string name;
    int age;
    float avg;
    int id;
    Student() {};
    Student(string name, int age, float avg, int id) : name(name), age(age), avg(avg), id(id) {};
};
void oneSt(Student st) {
    cout << "Name: " << st.name << endl << "Age: " << st.age << endl << "AVG: " << st.avg << endl << "Id: " << st.id << endl;
}
void print(Student* stu, int sz) {
    for (int i = 0; i < sz; i++) {
        oneSt(stu[i]);
        cout << endl;
    }
}
void havg(Student* st, int sz) {
    Student max = st[0];
    for (int i = 0; i < sz; i++) {
        if (max.avg < st[i].avg) max = st[i];
    }
    oneSt(max);
}
void idPrint(Student* st, int sz, int a) {
    int b;
    for (int i = 0; i < sz; i++) {
        if (a == st[i].id) b = i;
    }
    oneSt(st[b]);
}
void delId(Student*& st, int& sz, int a) {
    Student* buf = new Student[sz - 1];
    int s = -1;
    for (int i = 0; i < sz; i++) {
        if (st[i].id == a) {
            s = i;
            break;
        }
    }
    if (s != -1) {
        for (int i = 0; i < s; i++) {
            buf[i] = st[i];
        }
        for (int i = s + 1; i < sz; i++) {
            buf[i - 1] = st[i];
        }
        delete[] st;
        st = buf;
        sz--;
        cout << "Студент удален!";
    }
    else cout << "Неверный ID";
}
void addSt(Student*& st, int& sz, Student s) {
    Student* buf = new Student[sz + 1];
    for (int i = 0; i < sz; i++) {
        buf[i] = st[i];
    }
    buf[sz] = s;
    delete[] st;
    st = buf;
    sz++;
    cout << "Студент добавлен!";
}

void update(Student*& st, int sz, int stud, int choice) {
    int indexId;
    for (int i = 0; i < sz; i++) {
        if (st[i].id == stud) indexId = i;
    }
    if (choice == 1) {
        string a;
        cout << "Введите имя:" << endl;
        cin >> a;
        st[indexId].name = a;
    }
    if (choice == 2) {
        int b;
        cout << "Введите возраст:" << endl;
        cin >> b;
        st[indexId].age = b;
    }
    if (choice == 3) {
        float c;
        cout << "Введите средний балл:" << endl;
        cin >> c;
        st[indexId].avg = c;
    }
}

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int size = 3;

    Student s1("Vladimir", 16, 4.2, 4326);
    Student s2("Arsen", 17, 4.3, 3289);
    Student s3("Vadim", 17, 4.4, 9007);
    Student* st = new Student[size]{ s1, s2, s3 };

    cout << "Ученики:" << endl;
    print(st, size);
    cout << endl;
    int choice;
    int e = 0;
    while (e == 0) {
        cout << endl;
        cout << "Что делаем? \n 1 - Вывод самого умного студента \n 2 - Вывод по ID \n 3 - Удаление по ID \n 4 - Добавление студента \n 5 - Обновление данных студента \n 6 - Вывод студентов \n 0 - Выход" << endl;
        cin >> choice;
        switch (choice) {
        case 0:
            cout << "EXIT" << endl;
            e++;
            Sleep(500);
            cout << "- - - - -" << endl;
            Sleep(500);
            cout << "- - - -" << endl;
            Sleep(500);
            cout << "- - -" << endl;
            Sleep(500);
            cout << "- - " << endl;
            Sleep(500);
            cout << "-" << endl;
            break;
        case 1:
            havg(st, size);
            break;
        case 2:
            int id;
            cout << "Введите ID:";
            cin >> id;
            idPrint(st, size, id);
            break;
        case 3:
            int idDel;
            cout << "Введите id пользователя, которого надо удалить:";
            cin >> idDel;
            delId(st, size, idDel);
            break;
        case 4: {
            Student s4;
            cout << "Введите имя:";
            cin >> s4.name;
            cout << "Введите возраст:";
            cin >> s4.age;
            cout << "Введите средний балл:";
            cin >> s4.avg;
            cout << "Введите ID:";
            cin >> s4.id;
            addSt(st, size, s4);
            break;
        }
        case 5:
            int studId;
            cout << "Введите ID пользователя, которого надо изменить:" << endl;
            cin >> studId;
            int ch;
            cout << "Какие данные меняем? \n 1 - Имя \n 2 - Возраст \n 3 - Средний балл" << endl;
            cin >> ch;
            update(st, size, studId, ch);
        case 6:
            print(st, size);
            break;
        default:
            break;
        }


    }

}