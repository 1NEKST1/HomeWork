
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;
template <typename T>

class Array {
private:
    int size = 0;
    T* arr = new T[size];
public:
    ~Array() {
        delete[] arr;
    }

    int sizeArr() {
        return size;
    }

    void print() {
        for (int i = 0;i < size;i++) {
            cout << arr[i] << ' ';
        }
    }

    void addEl(T el) {
        T* buf = new T[size + 1];
        for (int i = 0;i < size;i++) {
            buf[i] = arr[i];
        }
        buf[size] = el;
        delete[] arr;
        arr = buf;
        size++;
    }

    void delEl() {
        T* buf = new T[size-1];
        for (int i = 0;i < size - 1;i++) {
            buf[i] = arr[i];
        }
        delete[] arr;
        arr = buf;
        size--;
    }

    T returnEl(int index) {
        for (int i = 0;i < size;i++) {
            if (i = index) return arr[i];
        }
    }

    void clearArr() {
        delete[] arr;
        arr = nullptr;
        size = 0;
    }
};



int main()
{
    Array<int> array;
    array.addEl(1);
    array.addEl(2);
    array.addEl(3);
    array.addEl(4);
    array.delEl();
    cout << array.sizeArr() << ' ' << array.returnEl(2) << endl;
    array.clearArr();
    array.print();

}

