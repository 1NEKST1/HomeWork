﻿#include <iostream>
#include <fstream>s
#include <string>
#include <windows.h>
#include <conio.h>
#define random(min, max) min + rand() % (max - min + 1) 

using namespace std;

int sizeArr = 20;
string* mapArr = new string[sizeArr];
struct Coord {
    int r1, r2, r3, r4, c1, c2, c3, c4;
    //Coord() {};
    Coord(int r1, int r2, int r3, int r4, int c1, int c2, int c3, int c4) : r1(r1), r2(r2), r3(r3), r4(r4), c1(c1), c2(c2), c3(c3), c4(c4) {};

};
int res = 0;
void showArr(string* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i == 3) cout << "   Очки:" << res;
        if (i == 5) cout << "   A - ВЛЕВО, D - ВПРАВО, S - ВНИЗ";
        cout << endl;
    }
}


void initMap(string*& arr) {

    arr[0] = "!!======================!!";

    for (int i = 1; i < 20; i++) {
        arr[i] = "!!                      !!";
    }

    arr[19] = "!!======================!!";

}
void clear() {
    system("cls");
}
int randBr() {
    int x = random(1, 7);
    if (x == 1) return 1;
    if (x == 2) return 2;
    if (x == 3) return 3;
    if (x == 4) return 4;
    if (x == 5) return 5;
    if (x == 6) return 6;
    if (x == 7) return 7;
}
void clearBr(string*& arr, int r1, int r2, int r3, int r4, int c1, int c2, int c3, int c4) {
    arr[r1][c1] = ' ';
    arr[r2][c2] = ' ';
    arr[r3][c3] = ' ';
    arr[r4][c4] = ' ';
}
void bricks(string*& arr, int& r1, int& r2, int& r3, int& r4, int& c1, int& c2, int& c3, int& c4) {
    arr[++r1][c1] = '#';
    arr[++r2][c2] = '#';
    arr[++r3][c3] = '#';
    arr[++r4][c4] = '#';
}

void right(string*& arr, int& r1, int& r2, int& r3, int& r4, int& c1, int& c2, int& c3, int& c4) {

    if (c1 != 23 && c2 != 23 && c3 != 23 && c4 != 23) {
        clearBr(arr, r1, r2, r3, r4, c1, c2, c3, c4);
        c1++;
        c2++;
        c3++;
        c4++;
    }




}

void left(string*& arr, int& r1, int& r2, int& r3, int& r4, int& c1, int& c2, int& c3, int& c4) {
    if (c1 != 2 && c2 != 2 && c3 != 2 && c4 != 2) {
        clearBr(arr, r1, r2, r3, r4, c1, c2, c3, c4);
        c1--;
        c2--;
        c3--;
        c4--;
    }


}
void game(string*& arr, int size, int& rs) {
    Coord p1(1, 1, 1, 2, 11, 12, 13, 12);
    Coord p2(1, 1, 2, 2, 11, 12, 11, 12);
    Coord p3(1, 2, 3, 4, 11, 11, 11, 11);
    Coord p4(1, 1, 2, 2, 11, 12, 12, 13);
    Coord p5(1, 1, 2, 2, 12, 13, 11, 12);
    Coord p6(1, 2, 3, 3, 11, 11, 11, 10);
    Coord p7(1, 2, 3, 3, 11, 11, 11, 12);
    int s = 0;
    int r1 = 0, r2 = 0, r3 = 0, r4 = 0, c1 = 0, c2 = 0, c3 = 0, c4 = 0;
    if (randBr() == 1) r1 = p1.r1, r2 = p1.r2, r3 = p1.r3, r4 = p1.r4, c1 = p1.c1, c2 = p1.c2, c3 = p1.c3, c4 = p1.c4, s = 1;
    else if (randBr() == 2) r1 = p2.r1, r2 = p2.r2, r3 = p2.r3, r4 = p2.r4, c1 = p2.c1, c2 = p2.c2, c3 = p2.c3, c4 = p2.c4, s = 2;
    else if (randBr() == 3) r1 = p3.r1, r2 = p3.r2, r3 = p3.r3, r4 = p3.r4, c1 = p3.c1, c2 = p3.c2, c3 = p3.c3, c4 = p3.c4, s = 3;
    else if (randBr() == 4) r1 = p4.r1, r2 = p4.r2, r3 = p4.r3, r4 = p4.r4, c1 = p4.c1, c2 = p4.c2, c3 = p4.c3, c4 = p4.c4, s = 4;
    else if (randBr() == 5) r1 = p5.r1, r2 = p5.r2, r3 = p5.r3, r4 = p5.r4, c1 = p5.c1, c2 = p5.c2, c3 = p5.c3, c4 = p5.c4, s = 5;
    else if (randBr() == 6) r1 = p6.r1, r2 = p6.r2, r3 = p6.r3, r4 = p6.r4, c1 = p6.c1, c2 = p6.c2, c3 = p6.c3, c4 = p6.c4, s = 6;
    else r1 = p7.r1, r2 = p7.r2, r3 = p7.r3, r4 = p7.r4, c1 = p7.c1, c2 = p7.c2, c3 = p7.c3, c4 = p7.c4, s = 7;


    while (r1 < 18 && r2 < 18 && r3 < 18 && r4 < 18 && arr[r4 + 1][c4] != '#') {
        showArr(arr, size);
        clear();
        clearBr(arr, r1, r2, r3, r4, c1, c2, c3, c4);
        bricks(arr, r1, r2, r3, r4, c1, c2, c3, c4);
        showArr(arr, size);
        char key;
        key = _getch();
        if (key == 100 && r4 < 18) {
            switch (s) {
            case 1:
                if (arr[r3 + 1][c3 + 1] != '#' && arr[r4 + 1][c4 + 1] != '#') {
                    right(arr, r1, r2, r3, r4, c1, c2, c3, c4);

                }
                break;
            case 2:
                if (arr[r2 + 1][c2 + 1] != '#' && arr[r4 + 1][c4 + 1] != '#') {
                    right(arr, r1, r2, r3, r4, c1, c2, c3, c4);

                }
                break;
            case 3:
                if (arr[r1 + 1][c1 + 1] != '#' && arr[r2 + 1][c2 + 1] != '#' && arr[r3 + 1][c3 + 1] != '#' && arr[r4 + 1][c4 + 1] != '#') {
                    right(arr, r1, r2, r3, r4, c1, c2, c3, c4);

                }
                break;
            case 4:
                if (arr[r4 + 1][c4 + 1] != '#') {
                    right(arr, r1, r2, r3, r4, c1, c2, c3, c4);

                }
                break;
            case 5:
                if (arr[r2 + 1][c2 + 1] != '#') {
                    right(arr, r1, r2, r3, r4, c1, c2, c3, c4);

                }
                break;
            case 6:
                if (arr[r1 + 1][c1 + 1] != '#' && arr[r1 + 1][c2 + 2] != '#' && arr[r3 + 1][c3 + 1] != '#') {
                    right(arr, r1, r2, r3, r4, c1, c2, c3, c4);

                }
                break;
            case 7:
                if (arr[r4 + 1][c4 + 1] != '#') {
                    right(arr, r1, r2, r3, r4, c1, c2, c3, c4);

                }
                break;
            }

        }
        if (key == 97 && r4 < 18) {
            switch (s) {
            case 1:
                if (arr[r1 + 1][c1 - 1] != '#') {
                    left(arr, r1, r2, r3, r4, c1, c2, c3, c4);

                }
                break;
            case 2:
                if (arr[r1 + 1][c1 - 1] != '#' && arr[r2 + 1][c2 - 1] != '#') {
                    left(arr, r1, r2, r3, r4, c1, c2, c3, c4);

                }
                break;
            case 3:
                if (arr[r1 + 1][c1 - 1] != '#' && arr[r2 + 1][c2 - 1] != '#' && arr[r3 + 1][c3 - 1] != '#' && arr[r4 + 1][c4 - 1] != '#') {
                    left(arr, r1, r2, r3, r4, c1, c2, c3, c4);

                }
                break;
            case 4:
                if (arr[r1 + 1][c1 - 1] != '#') {
                    left(arr, r1, r2, r3, r4, c1, c2, c3, c4);

                }
                break;
            case 5:
                if (arr[r3 + 1][c3 - 1] != '#') {
                    left(arr, r1, r2, r3, r4, c1, c2, c3, c4);

                }
                break;
            case 6:
                if (arr[r4 + 1][c4 - 1] != '#') {
                    left(arr, r1, r2, r3, r4, c1, c2, c3, c4);

                }
                break;
            case 7:
                if (arr[r1 + 1][c1 - 1] != '#' && arr[r2 + 1][c2 - 1] != '#' && arr[r3 + 1][c3 - 1] != '#') {
                    left(arr, r1, r2, r3, r4, c1, c2, c3, c4);

                }
                break;
            }

        }

        clear();

    }

}
int points(string*& arr) {
    int full = 0;
    int a = 0;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 26; j++) {
            if (arr[i][j] == '#') a++;
        }
        if (a == 22) {
            full = i;
            break;
        }
    }
    return full;
}

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
    initMap(mapArr);
    cout << endl;
    showArr(mapArr, sizeArr);
    clear();
    while (true) {
        game(mapArr, sizeArr, res);
        cout << endl << points(mapArr);
    }

    cout << endl << endl;

    // W - 119, A - 97, S - 115, D - 100, R - 82

}
