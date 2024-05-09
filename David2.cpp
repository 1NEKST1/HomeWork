#include <iostream>
#define random(min,max) min + rand() % (max - min + 1)
using namespace std;

// Добавление элемента в конец массива по индексу и вывод ступенчатого массива.
//void addElement(int**& arr, int rowIndex, int num) {
//    int size = _msize(arr[rowIndex]) / sizeof(arr[rowIndex][0]);
//    int* buf = new int[size + 1];
//    for (int i = 0;i < size;i++) {
//        buf[i] = arr[rowIndex][i];
//    }
//    buf[size] = num;
//    delete[] arr[rowIndex];
//    arr[rowIndex] = buf;
//
//}
////Вывод ступенчатого массива.
//void showArray(int** arr) {
//    int size1 = _msize(arr) / sizeof(arr[0]);
//    int size2;
//    for (int i = 0;i < size1;i++) {
//        size2 = _msize(arr[i]) / sizeof(arr[0][0]);
//        for (int j = 0; j < size2; j++) {
//            cout << arr[i][j] << ' ';
//            
//        }
//        cout << endl;
//        
//    }
//    cout << endl;
//}




//ДЗ 06.05

//Добавление нового массива по индексу.
void addArr(int** &arr, int indexArr) {
    int columnSize = _msize(arr[0]) / sizeof(arr[0][0]);
    int* buf = new int[columnSize];
    for (int i = 0;i < columnSize;i++) {
        buf[i] = random(1, 9);
    }
    int rowSize = _msize(arr) / sizeof(arr[0]) + 1;
    int** array2 = new int* [rowSize];
    for (int i = 0;i < rowSize ;i++) {
        array2[i] = new int[columnSize];
    }

    for (int i = 0; i < indexArr; i++) {
        for (int j = 0; j < columnSize; j++) {  
            array2[i][j] = arr[i][j];
        }
   }
    cout << "buf:";
    for (int i = 0;i < columnSize;i++) cout << buf[i] << ' ';
    cout << endl;
    array2[indexArr] = buf;
    for (int i = indexArr+1,g = indexArr; i < rowSize; i++,g++) {
        for (int j = 0; j < columnSize; j++) {
            array2[i][j] = arr[g][j];
        }
    }
    delete[] arr;
    arr = array2;

}
//Удаление массива по индексу.
void delRow(int**& arr, int indexRow) {
    int rowSize = _msize(arr) / sizeof(arr[0]);
    int columnSize = _msize(arr[0]) / sizeof(arr[0][0]);
    int** array2 = new int*[rowSize - 1];
    for (int i = 0;i < rowSize - 1;i++) {
        array2[i] = new int[columnSize];
    }
    for (int i = 0, g = 0; i < rowSize - 1;i++, g++) {
        if (i == indexRow) g++;
        for (int j = 0;j < columnSize;j++) {
            
            array2[i][j] = arr[g][j];
        }
    }
    delete[] arr;
    arr = array2;
    
    
}
//Добавление элемента по индексу массива, по индексу ряда.
void addEL(int**& arr, int indexRow, int indexColumn, int num) {
    int rowSize = _msize(arr) / sizeof(arr[0]);
    int columnSize = _msize(arr[0]) / sizeof(arr[0][0]);
    int* buf = new int[columnSize + 1];
    for (int i = 0,j = 0;i < columnSize + 1;i++,j++) {
        if (i == indexColumn) {
            buf[i] = num;
            i++;
            
        }
        buf[i] = arr[indexRow][j];
    }
    delete[] arr[indexRow];
    arr[indexRow] = buf;


}
//Удаление элемента по индексу в массиве по индексу ряда.
void delEl(int**& arr, int indexRow, int indexColumn){
    int rowSize = _msize(arr) / sizeof(arr[0]);
    int columnSize = _msize(arr[0]) / sizeof(arr[0][0]);
    int* buf = new int[columnSize - 1];
    for (int i = 0,j = 0; i < columnSize;i++,j++) {
        if (i == indexColumn) i++;
        buf[j] = arr[indexRow][i];
    }
    delete[] arr[indexRow];
    arr[indexRow] = buf;


}
//Удаление элемента в массиве по значению. ( по первому вхождению ).
void delNum(int**& arr, int number) {
    int rowSize = _msize(arr) / sizeof(arr[0]);
    int columnSize = _msize(arr[0]) / sizeof(arr[0][0]);
    int* buf = new int[columnSize - 1];
    int g = 0, c = 0;
    for (int i = 0;i < rowSize;i++) {
        for (int j = 0; j < columnSize; j++) {
            if (arr[i][j] == number && c < 1) {
                g = i;
                c++;
            }
            
        }
    }
    if (c > 0) {
        for (int i = 0, j = 0; i < columnSize - 1; i++, j++) {
            if (arr[g][j] == number && c < 2) {
                j++;
                c++;
            }
            buf[i] = arr[g][j];
        }

        delete[] arr[g];
        arr[g] = buf;
    }
    
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
int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    int row = 4;
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
    //addArr(array, 4);
    //delRow(array, 1);
    //addEL(array, 1, 2, 0);
    //delEl(array, 1, 2);
    delNum(array, 2);
    showArray(array);
    










}