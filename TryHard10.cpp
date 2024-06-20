#include <iostream>
#define random(min,max) min + rand() % (max - min + 1)
using namespace std;

// 1
int sum(int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// 2
int max(int* arr, int size) {
    int current = arr[0];
    int max = 0;
    int a = 0;
    for (int i = 1;i < size;i++) {
        if (current < arr[i]) {
            current = arr[i];
            max = i;
            a++;
        }
        
    }
    if (a == 0) max = 0;
    return max;
}

// 3
void sort(int* arr, int size) {
    for (int i = 0;i < size - 1;i++) {
        for (int j = 0;j < size - i - 1;j++) {
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
        }
    }
}

// 5 
struct Student {
    string name;
    int age;
    float avg;
    int id;
    Student() {};
    Student(string name, int age, float avg, int id) : name(name), age(age), avg(avg), id(id) {};
};
void oneSt(Student st) {
    cout << "Name: " << st.name << endl << "Age: " << st.age << endl << "AVG: " << st.avg << endl << "Id: " << st.id << endl;
}
void print(Student* stu, int sz) {
    for (int i = 0; i < sz; i++) {
        oneSt(stu[i]);
        cout << endl;
    }
}

void delId(Student*& st, int& sz, int a) {
    Student* buf = new Student[sz - 1];
    int s = -1;
    for (int i = 0; i < sz; i++) {
        if (st[i].id == a) {
            s = i;
            break;
        }
    }
    if (s != -1) {
        for (int i = 0; i < s; i++) {
            buf[i] = st[i];
        }
        for (int i = s + 1; i < sz; i++) {
            buf[i - 1] = st[i];
        }
        delete[] st;
        st = buf;
        sz--;
        cout << "Студент удален!";
    }
    else cout << "Неверный ID";
}
void addSt(Student*& st, int& sz, Student s) {
    Student* buf = new Student[sz + 1];
    for (int i = 0; i < sz; i++) {
        buf[i] = st[i];
    }
    buf[sz] = s;
    delete[] st;
    st = buf;
    sz++;
    cout << "Студент добавлен!";
}
// Двумерные массивы
// 1 
int sumAll(int** arr,int Row, int Col) {
    int sum = 0;
    for (int i = 0;i < Row;i++) {
        for (int j = 0;j < Col;j++) {
            sum += arr[i][j];
        }

    }
    return sum;
}

// 2
void transport(int**& arr, int Row, int Col) {
    cout << "Что меняем\n1 - СТРОКИ 2 - СТОЛБЦЫ: ";
    int choice;
    cin >> choice;
    int num1,num2;
    cout << "Что меняем(0,1,2,3)?: ";
    cin >> num1;
    cout << "С чем?: ";
    cin >> num2;
    if (choice == 1) {
        for (int i = 0;i < Row;i++) {
            for (int j = 0;j < Col;j++) {
                if (i == num1) {
                    swap(arr[i][j], arr[num2][j]);

                }
            }
        }


    }
    else if (choice == 2) {
        for (int i = 0;i < Row;i++) {
            for (int j = 0;j < Col;j++) {
                if (j == num1) {
                    swap(arr[i][num1], arr[i][num2]);

                }
            }
        }
    }
}
//3
long long mult(int** arr, int** arr2, int Row, int Col) {
    long long mul = 1, mul2 = 1;
    for (int i = 0;i < Row;i++) {
        for (int j = 0;j < Col;j++) {
                mul *= arr[i][j];
        }
    }
    for (int i = 0;i < Row;i++) {
        for (int j = 0;j < Col;j++) {
            mul2 *= arr2[i][j];
        }
    }
    return mul * mul2;
}
//4
void position(int**& arr, int Row, int Col) {
    int num;
    cout << "Какой элемент вы хотите найти?";
    cin >> num;
    int a = 0;
    for (int i = 0;i < Row;i++) {
        for (int j = 0;j < Col;j++) {
            if (num == arr[i][j]) {
                cout << i << ' ' << j;
                a++;
                break;
            }

        }
    }
    if (a == 0) cout << "Такого элемента нет";
}
void showArr(int* arr, int size) {
    for (int i = 0;i < size;i++) {
        cout << arr[i] << ' ';
    }
}

void showTwoArr(int** arr, int Row, int Col) {
    for (int i = 0;i < Row;i++) {
        for (int j = 0;j < Col;j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
}
int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    int size = 5;
    int* arr = new int[size] { 9, 3, 6, 5, 2};

    /*int size = 3;
    Student s1("Vladimir", 16, 4.2, 4326);
    Student s2("Arsen", 17, 4.3, 3289);
    Student s3("Vadim", 17, 4.4, 9007);
    Student* st = new Student[size]{ s1, s2, s3 };*/
    int Row = 4;
    int Col = 4;
    int** array = new int*[Row];
    for (int i = 0;i < Row;i++) {
        array[i] = new int[Col];
    }
    for (int i = 0;i < Row;i++) {
        for (int j = 0;j < Col;j++) {
            array[i][j] = random(1, 9);
            cout << array[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    int** array2 = new int* [Row];
    for (int i = 0;i < Row;i++) {
        array2[i] = new int[Col];
    }
    for (int i = 0;i < Row;i++) {
        for (int j = 0;j < Col;j++) {
            array2[i][j] = random(1, 9);
            cout << array2[i][j] << ' ';
        }
        cout << endl;
    }

}








































































    










    
        
            
        
    


        
    



        


        
    

    


    

















    







    
               

        

    
    
 
    
    
    













