#include <iostream>
#include <fstream>
#include <string>
#include "windows.h"
#define random(min, max) min + rand() % (max - min + 1) 
using namespace std;
//int numStr(string path) {
//    int n = 0;
//    ifstream in(path);
//    if (in.is_open()) {
//        string str;
//        while (getline(in, str)) {
//            n++;
//        }
//    
//    }
//    return n;
//}
//
//void initArr(string path, string* arr) {
//    int s = 0, b = 0;
//    ifstream in(path);
//    if (in.is_open()) {
//        string str;
//        while (!in.eof()) {
//            str = "";
//            getline(in, str, '.');
//            if (b % 2 == 1) {
//                arr[s++] = str;
//            }
//            b++;
//        }
//
//    }
//}
//void showArr(string* arr, int& n) {
//    if (n == 0) n++;
//    for (int i = 0; i < n-1; i++) {
//        cout << i + 1 << '.' << arr[i] << endl; 
//    }
//    
//}
//
//void addTask(string* arr, string str, int& n) {
//    arr[n-1] = str;
//    n++;
//}
//void initFile(string* arr, string path, int &n) {
//    ofstream out(path);
//    if (out.is_open()) {
//        for (int i = 0; i < n-1; i++) {
//            out << i+1 << '.' << arr[i] << endl;
//        }
//    }
//
//    }
//    
//    
//
//void delStr(string* &arr, int& n, int a) {
//    string* buf = new string[n];
//    for (int i = 0,j = 0; i < n; i++, j++) {
//        if (i == a-1) i++;
//        buf[j] = arr[i];
//    }
//    n--;
//    delete[] arr;
//    arr = buf;
//
//    
//}
//void del(string*& arr) {
//    delete[] arr;
//}
struct Point {
    int x;
    int y;
    string color;
    Point() {};
    Point(int a, int b, string color) : x(a), y(b), color(color) {};

};
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
void delId(Student* &st, int &sz, int a) {
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
    Student* buf = new Student[sz+1];
    for (int i = 0; i < sz; i++) {
        buf[i] = st[i];
    }
    buf[sz] = s;
    delete[] st;
    st = buf;
    sz++;
    cout << "Студент добавлен!";
}

void update(Student*& st, int sz,int stud, int choice) {
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

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //    int size = numStr("task.txt");
    //    string* array = new string[10];
    //    initArr("task.txt", array);
    //    //showArr(array, size);
    //    
    //
    //    int choice;
    //    
    //    int a = 0;
    //    while (a == 0) {
    //        cout << "Что делаем? \n 1 - добавить \n 2 - удалить \n 3 - вывести \n 4 - очистить \n 0 - Выход" << endl;
    //        cin >> choice;
    //        switch (choice) {
    //        case 0:
    //        {
    //            cout << endl;
    //            cout << "Выход";
    //            initFile(array, "task.txt", size);
    //            a++;
    //            break;
    //        }
    //        case 1:
    //        {
    //            string str;
    //            cout << "Введите задачу:";
    //            cin >> str;
    //            addTask(array, str, size);
    //            cout << "Элемент добавлен";
    //            system("cls");
    //            break;
    //        }
    //        case 2:
    //        {
    //            int s;
    //            cout << "Какую задачу удалить?:";
    //            cin >> s;
    //            delStr(array, size, s);
    //            cout << endl;
    //            cout << "Строка удалена!";
    //            system("cls");
    //            break;
    //        }
    //        case 3:
    //            cout << endl;
    //            showArr(array, size);
    //            break;
    //        case 4:
    //            del(array);
    //            size = -1;
    //            break;
    //
    //        default:
    //            break;
    //
    //        }
    //    }
    int size = 3;


    Student s1("Vladimir", 16, 4.2, 4326);
    Student s2("Arsen", 17, 4.3, 3289);
    Student s3("Vadim", 17, 4.4, 9007);
    Student* st = new Student[size]{ s1, s2, s3 };



    /*oneSt(s1);
    cout << endl;*/
    cout << "Все пользователи:" << endl;
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
        case 4:
        {
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

        //havg(st, size);
        //cout << endl;
        //cout << "Введите id пользователя:";
        //cin >> id;
        //idPrint(st, size, id);
        //cout << endl;
        //cout << "Введите id пользователя, которого надо удалить:";
        //cin >> idDel;
        //delId(st, size, idDel);
        //cout << endl;
        //print(st, size);
        //addUser(st, size);
        //print(st, size);




    }
}


