#include <iostream>
using namespace std;
//Возвращаемое_значение имя_функции(параметры){
    //  блок_кода(тело)
    //}
//1 Счастливое число
//int h1 = 0, h2 = 0;
//void happiness(int a) {
//    int b = a;
//    for (int i = 0;i < 3;i++) {
//        h1 += a % 10;
//        a /= 10;
//
//    }
//
//    for (int i = 0;i < 3;i++) {
//        h2 += a % 10;
//        a /= 10;
//
//    }
//    cout << b << endl;
//    if (h1 == h2 && b > 99999 && b < 1000000) cout << "Число счастливое";
//    if (h1 != h2 && b > 99999 && b < 1000000) cout << "Число не счастливое";
//    if (b < 100000 || b > 999999) cout << "Число не шестизначное";
    
    
//} 


//2 Написать функцию, реализующую алгоритм линейного поиска заданного ключа в одномерном массиве.
void key(int arr[], const int S,int a) {
    for (int i = 0;i < S;i++) {
        arr[i] = 0 + rand() % 10;
        cout << arr[i] << ' ';
    }
    cout << endl;
    for (int i = 0;i < S;i++) {
        if (arr[i] == a) cout << i << " ";
       
    }
}
// Я не уверен, что правильно понял ,что во втором делать, но сделал так, чтобы выдавало индекс ключа



int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
    //1
    /*int n;
    cout << "Введите шестизначное число:";
    cin >> n;
    happiness(n);*/
    //2
    const int SIZE = 10;
    int array[SIZE];
    int key1;
    cout << "Введите ключ:";
    cin >> key1;
   
    key(array, SIZE, key1);



}








    
        
            
        
    


        
    



        


        
    

    


    

















    







    
               

        

    
    
 
    
    
    













