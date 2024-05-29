#include <iostream>
#define random(min,max) min + rand() % (max - min + 1)
#include <fstream>
#include <string>
#include "windows.h"
using namespace std;



int numStr(string path) {
    int n = 0;
    ifstream in(path);
    if (in.is_open()) {
        string str;
        while (getline(in, str)) {
            n++;
        }
    
    }
    return n;
}

void initArr(string path, string* arr, int sz) {
    ifstream in;
    in.open(path);
    string str;
    int a = 0;
    if (in.is_open()){
        while (getline(in, str)) {
            arr[a++] = str;
        }
    }
    in.close();
}
void showArr(string* arr, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i][0] != '1' && arr[i][0] != '2' && arr[i][0] != '3' && arr[i][0] != '4' && arr[i][0] != '5' && arr[i][0] != '6' && arr[i][0] != '7' && arr[i][0] != '8' && arr[i][0] != '9') {
            cout << i + 1 << ". ";
        }
        cout << arr[i] << endl;
    }
    
    
}

void addTask(string* arr, string str, int& n) {
    arr[n] = str;
    n++;
}
void initFile(string* arr, string path, int& n) {
    ofstream out;
    int a = 0;
    out.open(path);
    if (out.is_open())
    {
        for (int i = numStr(path); i < n; i++) {
            if (arr[i][0] != '1' && arr[i][0] != '2' && arr[i][0] != '3' && arr[i][0] != '4' && arr[i][0] != '5' && arr[i][0] != '6' && arr[i][0] != '7' && arr[i][0] != '8' && arr[i][0] != '9') {
                out << i + 1 << ". ";
            }
            out << arr[i] << endl;
        }
    }
    out.close();
}
void delStr(string* &arr, int& n, int a) {
    string* buf = new string[n];
    for (int i = 0,j = 0; i < n; i++, j++) {
        if (i == a-1) i++;
        buf[j] = arr[i];
    }
    n--;
    delete[] arr;
    arr = buf;

}
void del(string*& arr) {
    delete[] arr;
}

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int size = numStr("task.txt");
    string* array = new string[10];
    initArr("task.txt", array, size);
    showArr(array, size);

    int choice;
    int d = 0;
    int a = 0;
    while (a == 0) {
        cout << "Что делаем? \n 1 - добавить \n 2 - удалить \n 3 - вывести \n 4 - очистить \n 0 - Выход" << endl;
        cin >> choice;
        switch (choice) {
        case 0:
        {
            cout << endl;
            cout << "Выход";
            initFile(array, "task.txt", size);
            a++;
            break;
        }
        case 1:
        {
            string str;
            cout << "Введите задачу:";
            cin >> str;
            addTask(array, str, size);
            cout << "Элемент добавлен";
            system("cls");
            break;
        }
        case 2:
        {
            int s;
            cout << "Какую задачу удалить?:";
            cin >> s;
            delStr(array, size, s);
            initFile(array, "task.txt", size);
            cout << endl;
            cout << "Строка удалена!";
            system("cls");
            break;
        }
        case 3:
            if (d > 0) {
                cout << "Задач нет!" << endl;
                break;
            }
            initFile(array, "task.txt", size);
            showArr(array, size);
            break;
        case 4:
            del(array);
            cout << "Задачи удалены" << endl;
            d++;
            break;


        }


    }
}

































































