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
    int* p = &size;
    int* array = new int[size];
    for (int i = 0;i < size;i++) {
        array[i] = random(1, 9);
        cout << array[i] << ' ';
    }
    cout << endl;
    cout << p;
}








    
        
            
        
    


        
    



        


        
    

    


    

















    







    
               

        

    
    
 
    
    
    













