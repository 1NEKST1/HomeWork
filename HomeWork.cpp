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
        ofstream out;
        out.open("h.txt");
        string str;
        int s = 0;
        while (getline(in, str) && a != s) {
            out << str << endl;
            s++;
        }
        in.close();
        cout << "ФАЙЛ СКОПИРОВАН";
    }
    else {
        cout << "ФАЙЛ НЕ НАЙДЕН!";
    }
    in.close();  

}
int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    copyFile("hm.txt", 2);
    cout << endl;
    showFile("h.txt");


}