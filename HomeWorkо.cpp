
#include <iostream>
#include <string>
#define random(min, max) min + rand() % (max - min + 1)

using namespace std;

//1
template <typename T>
T maxim(T arr[], int size) {
    T m = arr[0];
    for (int i = 1;i < size;i++) {
        if (m < arr[i]) m = arr[i];
    }
    return m;
}

template <typename T>
T minim(T arr[], int size) {
    T m = arr[0];
    for (int i = 1;i < size;i++) {
        if (m > arr[i]) m = arr[i];
    }
    return m;
}

template <typename T>
void sort(T arr[], int size) {
    for (int i = 0;i < size;i++) {
        for (int j = 0;j < size;j++) {
            if (arr[i] < arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
} 

template <typename T>
void change(T arr[], int size, T a, int index) {
    for (int i = 0;i < size;i++) {
        if (i == index) arr[i] = a;
    }

}

template <typename T>
void printArr(T arr, int size) {
    for (int i = 0;i < size;i++) {
        cout << arr[i] << ' ';
    }
}

//2


template <typename T>
class Matrix{
private:
    int Row;
    int Col;
    T** arr;
public:
    Matrix(int r, int c) {
        this->Row = r;
        this->Col = c;
        arr = new T*[Row];
        for (int i = 0;i < Row;i++) {
            arr[i] = new T[Col];
        }
    }
    void clear() {
        Row = 0;
        Col = 0;
    }
    void cinUser() {
        T c;
        for (int i = 0;i < Row;i++) {
            for (int j = 0;j < Col;j++) {
                cout << "Введите элемент:";
                cin >> c;
                arr[i][j] = c;
                c = 0;
            }
        }
    }
    
    void cinRand() {
        for (int i = 0;i < Row;i++) {
            for (int j = 0;j < Col;j++) {
                arr[i][j] = random(1,9);
            }
        }
    }

    T maxim() {
        T maxim = arr[0][0];
        for (int i = 0;i < Row;i++) {
            for (int j = 0;j < Col;j++) {
                if (maxim < arr[i][j]) swap(maxim, arr[i][j]);
            }
        }
        return maxim;
    }

    T minim() {
        T minim = arr[0][0];
        for (int i = 0;i < Row;i++) {
            for (int j = 0;j < Col;j++) {
                if (minim > arr[i][j]) swap(minim, arr[i][j]);
            }
        }
        return minim;
    }

    void print() {
        for (int i = 0;i < Row;i++) {
            for (int j = 0;j < Col;j++) {
                cout << arr[i][j] << ' ';
            }
            cout << endl;
        }
    }


};

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
    //const int size = 8;
    //int arr[size]{ 1,2,3,4,5,6,8,9 };
    //cout << maxim(arr, size);
    //cout << minim(arr, size);
    //change(arr, size, 5687, 3);
    Matrix<int> a(3,3);
    a.cinRand();
    a.print();
    //cout << a.minim();

}