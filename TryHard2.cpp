#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    /*const int S = 10;
    int arr[S];
    int max, min;
    cout << "min:";
    cin >> min;
    cout << "max:";
    cin >> max;
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        arr[i] = min + rand() % (max - min + 1);
        cout << arr[i] << ' ';  
    }*/
    //1 Нахождение минимального и максимального числа
  /*  int ma = arr[0];
    int mi = arr[0];
    cout << endl;
    for (int i = 1; i < 10; i++) {
        if (arr[i] < mi) mi = arr[i];
        if (ma < arr[i]) ma = arr[i];
    }
    cout << endl; 
    cout << "min = " << mi << endl;
    cout << "max = " << ma;*/
    //2 найти сумму элементов, значения которых меньше указанного пользователем
    /*cout << endl;
    int n;
    int a = 0;
    cout << "Введите ограничение:";
    cin >> n;
    for (int i = 1; i < 10; i++) {
        if (arr[i] < n) a += arr[i];
    }
    cout << a;*/
    //3 определить месяц, в котором прибыль была максимальна и месяц, в котором прибыль была минимальна с учетом выбранного диапазона.
  /*  const int S = 12;
    int arr[S], b, p;
    int max = 7, min = 6;
    cout << "Введите прибыль:";
    cin >> p;
    int x, y;
    cout << "Введите начало диапозона:";
    cin >> x;
    cout << "Введите конец диапозона:";
    cin >> y;
    srand(time(NULL));
    for (int i = 0; i < 12; i++) {
        b = min + rand() % (max - min + 1);
        arr[i] = p / b;
        p = p - arr[i];
        cout << arr[i] << ' ';
    }
    int ma = arr[x];
    int mi = arr[x];
    cout << endl;
    for (int i = x; i < y+1; i++) {
        cout << arr[i - 1] << ' ';
        if (arr[i-1] > ma) ma = arr[i-1];
        if (arr[i-1] < mi) mi = arr[i-1];
    }
    cout << endl;
    cout << "min = " << mi << endl;
    cout << "max = " << ma;*/

}
    









    
        
            
        
    


        
    



        


        
    

    


    

















    







    
               

        

    
    
 
    
    
    













