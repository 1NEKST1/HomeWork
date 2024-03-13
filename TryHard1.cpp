#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    const int S = 10;
    int arr[S];
    int max, min;
    bool flag;
    cout << "min:";
    cin >> min;
    cout << "max:";
    cin >> max;
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        arr[i] = min + rand() % (max - min + 1);
        cout << arr[i] << ' ';
    }
    for (int j = 0;j <= S; j++){
        for (int i = 0; i < S - 1 - j;i++) {
            flag = true;
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                flag = false;
            }
           
        }
        if (flag == true) break;
    
    }
    cout << endl;
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << ' ';
    }








}
    









    
        
            
        
    


        
    



        


        
    

    


    

















    







    
               

        

    
    
 
    
    
    













