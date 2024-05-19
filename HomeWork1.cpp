#include <iostream>
#define random(min,max) min + rand() % (max - min + 1)
#include <fstream>
#include <string>
#include "windows.h"
#include <iostream>
using namespace std;
void showFile(string path) {
    ifstream in(path);
    if (in.is_open()) {
        string str;
        while (getline(in, str)) {
            cout << str << endl;

        }

    }
    in.close();
}
void copyFile(string path, int a) {
    ifstream in(path);
    if (in.is_open()) {
        string path1 = "h.txt";
        ofstream out;
        out.open(path1);
        string str;
        int s = 0;
        while (getline(in, str)) {
            if (out.is_open() && s != a) {
                s++;
                out << str << endl;
            }
        }
        out.close();
        cout << "Файл был скопирован!";

    }
    else {
        cout << "ФАЙЛ НЕ НАЙДЕН!";
    }
    in.close();
}

int main()
{
    srand(time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
    copyFile("hm.txt", 2);
    cout << endl;
    showFile("h.txt");
    

}