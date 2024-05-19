#include <iostream>
#define random(min,max) min + rand() % (max - min + 1)
#include <fstream>
#include <string>
#include "windows.h"
#include <iostream>
using namespace std;
void quickSort(int* arr, int left, int right) {
    if (left >= right) return;
    int marker = left - 1;
    for (int curIndex = left; curIndex <= right; curIndex++) {
        if (arr[curIndex] <= arr[right]) {
            marker++;
            if (curIndex > marker) swap(arr[curIndex], arr[marker]);
        }
    }
    quickSort(arr, left, marker - 1);
    quickSort(arr, marker + 1, right);

}
void showArray(int* arr) {
    int size = _msize(arr) / sizeof(arr[0]);
    for (int i = 0;i < size;i++) {
        cout << arr[i] << ' ';
        
    }
    
}

int main()
{
    srand(time(NULL));
    int row = 4;
    int col = 4;
    int* array = new int[10] {3, 2, 4, 0, 1, 8, 7, 6, 5, 5};
    showArray(array);
    cout << endl;
    quickSort(array, 0, 9);
    showArray(array);
    

}