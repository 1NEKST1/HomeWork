#include <iostream>
#define random(min,max) min + rand() % (max - min + 1)
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    int size;
    cout << "Введите размер:";
    cin >> size;
    //int s = size;
    int* array = new int[size];
    for (int i = 0;i < size;i++) {
        array[i] = random(1, 9);
        cout << array[i] << ' ';
    }
    cout << endl;
    // 1. Добавление массива в конец другого массива   
        /*int* array2 = new int[size];
        for (int i = 0;i < size;i++) {
            array2[i] = random(1, 9);
            cout << array2[i] << ' ';
        }
        cout << endl;
        size += size;
        int* buf = new int[size];
        for (int i = 0,j = 0;i < size;i++,j++) {
            while (i < s) {
                buf[i] = array[i];
                i++;
            }
            buf[i] = array2[j];
        }
        delete[] array;
        array = buf;
        for (int i = 0;i < size;i++) {
            cout << array[i] << ' ';
        }*/


        //2. Добавление массива по индексу в другой массив
   /* int* array2 = new int[size];
    for (int i = 0;i < size;i++) {
        array2[i] = random(1, 9);
        cout << array2[i] << ' ';
    }
    cout << endl;
    int index;
    cout << "Введите индекс:";
    cin >> index;
    int* buf = new int[size * 2];
    for (int i = 0;i < index;i++) buf[i] = array[i];

    for (int i = index,j = 0;j < size;i++,j++) {
        buf[i] = array2[j];
    }
    for (int i = index, j = index + size,g = 0;g < size;i++,j++,g++) buf[j] = array[i];
    size += size;
    delete[] array;
    array = buf;
    for (int i = 0;i < size;i++) {
        cout << array[i] << ' ';
    }*/
   

        //3. Удаление элемента из массива по занчению по первому вхождению
   /* int a;
    cout << "Введите значение";
    cin >> a;
    int* buf = new int[size - 1];
    for (int i = 0, j = 0;j < size;i++,j++) {
        if (array[i] == a) i++;
        buf[j] = array[i];
    }
    delete[] array;
    array = buf;
    size--;
    for (int i = 0;i < size;i++) {
        cout << array[i] << ' ';
    }*/













}