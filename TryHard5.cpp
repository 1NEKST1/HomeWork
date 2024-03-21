#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    const int R = 4;
    const int C = 4;
    int arr[R][C] = {};
    srand(time(NULL));
    int max, min;
    cout << "min:";
    cin >> min;
    cout << "max:";
    cin >> max;



    for (int i = 0;i < R;i++) {
        for (int j = 0;j < C;j++) {
            arr[i][j] = min + rand() % (max - min + 1);
        }

    }
    for (int i = 0;i < R;i++) {
        for (int j = 0;j < C;j++) cout << arr[i][j] << ' ';
        cout << endl;
    }
    cout << endl;
    //2 Для каждой строки двумерного массива
    // выяснить количество элементов,
    // последняя цифра которых равна 'a'
        //int a;
        //cout << "Введите полседнюю цифру:";
        //cin >> a;
        //int s = 0;
        //for (int i = 0;i < R;i++) {
        //    for (int j = 0;j < C;j++) {
        //        if (arr[i][j] % 10 == a) s++;
        //    }
        //    cout << s << endl;
        //    s = 0;
        //}

    // 1.
    // Найти минимальную сумму элементов строки
        //int sum2 = 0;
        //int sum3 = 0;
        //for (int i = 0;i < R;i++) {
        //    sum2 += arr[0][i];


        //}
        //
        //for (int j = 1;j < R;j++) {
        //    for (int i = 0;i < C;i++) {
        //        sum3 += arr[j][i];

        //    
        //    }
        //    if (sum2 > sum3) sum2 = sum3;
        //    
        //    sum3 = 0;

        //    
        //}

        //cout << endl;
        //cout << "Минимальная сумма:" << sum2;


    // 3 задачу не понял

}







    
        
            
        
    


        
    



        


        
    

    


    

















    







    
               

        

    
    
 
    
    
    













