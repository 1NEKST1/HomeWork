
#include <iostream>
#include <fstream>
#include <string>
#include "windows.h"
#define random(min, max) min + rand() % (max - min + 1)

using namespace std;

// 1
int** createAndFillArray(int r, int c) {
    int** arr = new int* [r];
    for (int i = 0;i < r;i++) {
        arr[i] = new int[c];
    }
    for (int i = 0;i < r;i++) {
        for (int j = 0;j < c;j++) {
            arr[i][j] = random(1, 100);
        }
    }
    return arr;
}

// 2
void del(int**& arr, int& r, int& c,int indexRow, int indexCol) {
    int** buf = new int*[r - 1];
    for (int i = 0;i < r - 1;i++) {
        buf[i] = new int[c - 1];
    }
    for (int i = 0,a = 0;i < r;i++,a++) {
        if (i == indexRow) i++;
        for (int j = 0, b = 0;j < c;j++,b++) {
            
            if (j == indexCol) j++;
            buf[a][b] = arr[i][j];
        }
    }
    r--;
    c--;
    delete[] arr;
    arr = buf;
}

// 3
void rotateArray90Degrees(int**& arr, int& r, int& c) {
    swap(r, c);
    int** buf = new int* [r];
    for (int i = 0;i < r;i++) {
        buf[i] = new int[c];
    }
    int a = 3, b = 0;
    for (int i = 0;i < r;i++) {
        for (int j = 0;j < c;j++) {
            buf[i][j] = arr[a][b];
            a--;

        }
        a = 3;
        b++;
    }
    delete[] arr;
    arr = buf;
}

void showArr(int** arr,int r, int c) {
    for (int i = 0;i < r;i++) {
        for (int j = 0;j < c;j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
}
int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int Row = 4;
    int Col = 4;
    int** arr = new int* [Row];
    for (int i = 0;i < Row;i++) {
        arr[i] = new int[Col];
    }
    for (int i = 0;i < Row;i++) {
        for (int j = 0;j < Col;j++) {
            arr[i][j] = random(1, 100);
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }


}