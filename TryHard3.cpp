#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    const int S = 10;
    int arr[S];
    int max, min;
    int buf;
    cout << "min:";
    cin >> min;
    cout << "max:";
    cin >> max;
    srand(time(NULL));
    for (int i = 0; i < S; i++) {
        arr[i] = min + rand() % (max - min + 1);
        cout << arr[i] << ' ';
    }
    cout << endl;
    for (int i = 1; i < S; i++) {
        if (arr[i - 1] > arr[i]) {
            buf = arr[i];
            for (int j = i; j >= 0;j--) {
                if (arr[j - 1] > buf) arr[j] = arr[j - 1];
                else {
                    arr[j] = buf;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < S; i++) {
        cout << arr[i] << ' ';
    }
}







    
        
            
        
    


        
    



        


        
    

    


    

















    







    
               

        

    
    
 
    
    
    













