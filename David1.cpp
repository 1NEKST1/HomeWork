#include <iostream>
#define random(min,max) min + rand() % (max - min + 1)
using namespace std;
// Добавление элемента в конец массива по индексу и вывод ступенчатого массива.

void addElement(int**& arr, int rowIndex, int num) {
    int size = _msize(arr[rowIndex]) / sizeof(arr[rowIndex][0]);
    int* buf = new int[size + 1];
    for (int i = 0;i < size;i++) {
        buf[i] = arr[rowIndex][i];
    }
    buf[size] = num;
    delete[] arr[rowIndex];
    arr[rowIndex] = buf;

}
void showArray(int** arr) {
    int size1 = _msize(arr) / sizeof(arr[0]);
    int size2;
    for (int i = 0;i < size1;i++) {
        size2 = _msize(arr[i]) / sizeof(arr[0][0]);
        for (int j = 0; j < size2; j++) {
            cout << arr[i][j] << ' ';
            
        }
        cout << endl;
        
    }
    cout << endl;
}
//void initArray(int* arr) {
//
//    int size = _msize(arr) / sizeof(arr[0]);
//    for (int i = 0;i < size;i++) {
//        arr[i] = random(1, 9);
//    }
//
//}
////void showArray(int* arr) {
////
////    int size = _msize(arr) / sizeof(arr[0]);
////    for (int i = 0;i < size;i++) {
////        cout << arr[i] << ' ';
////    }
////
////}
//
//void addEndArray(int*& arr, int n) {
//    int size = _msize(arr) / sizeof(arr[0]);
//    int* buf = new int[size + 1];
//    for (int i = 0;i < size;i++) buf[i] = arr[i];
//    buf[size] = n;
//    delete[] arr;
//    arr = buf;
//}
//void indexArray(int*& arr, int a, int n) {
//    int  size = _msize(arr) / sizeof(arr[0]);
//    int* buf = new int[size + 1];
//    for (int i = 0;i < a;i++) {
//        buf[i] = arr[i];
//    }
//    buf[a] = n;
//    for (int i = a+1,j = a;i < size+1;i++,j++) {
//        buf[i] = arr[j];
//    }
//
//
//    
//    
//    delete[] arr;
//    arr = buf;
//}
//void indexDelArray(int*& arr, int a) {
//    int  size = _msize(arr) / sizeof(arr[0]);
//    int* buf = new int[size - 1];
//    for (int i = 0,j = 0;i < a;i++,j++) {
//        if (i == a) j++;
//        buf[i] = arr[j];
//    }
//    
//    delete[] arr;
//    arr = buf;
//}
//void showArray(int* arr) {
//        int size = _msize(arr) / sizeof(arr[0]);
//
//        for (int i = 0;i < size;i++) {
//            cout << arr[i] << ' ';
//        }
//
//}
//
//
int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    //    int* array = new int[5];
    //
    //   /* int** array1 = new int*[3];
    //    for(int i = 0;i < 3;i++) {
    //        array1[i] = new int[4];
    //    }*/
    //
    //    initArray(array);
    //    showArray(array);
    //    indexDelArray(array, 2);
    //    cout << endl;
    //    showArray(array);
    int row = 3;
    int column = 4;
    int** array = new int*[row];
    for (int i = 0;i < row;i++) {
        array[i] = new int[column];
    }
    for (int i = 0;i < row;i++) {
        for (int j = 0;j < column;j++) {
            array[i][j] = random(1, 9);
           
        }
;
    }
    showArray(array);
    cout << endl;
    addElement(array, 2, 0);
    showArray(array);

    











}