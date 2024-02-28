#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    //1
    /*int n, a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, s = 0, s2 = 0, s3 = 0;
    cout << "Введите шестизначное число:";
    cin >> n;
    s3 = n;
    d = n % 10;
    n = n / 10;
    e = n % 10;
    n = n / 10;
    f = n % 10;
    n = n / 10;
    a = n % 10;
    n = n / 10;
    b = n % 10;
    n = n / 10;
    c = n % 10;
    s = a + b + c;
    s2 = d + e + f;
    if(s == s2 && s3 < 1000000) cout << "Ваше число счастливое!";
    else if (s != s2 && s3 < 1000000) cout << "Ваше число не счастливое:(";
    else cout << "ERROR";*/

    //2
    /*int a, b, c, d;
    int n, d1, d2, d3, d4, f, t;
    cout << "Введите четырёхзначное число:" << endl;
    cin >> n;
    if (n > 9999)
    {
        cout << "Число не 4-х значное";
            
    }
    else
    {
        
        d4 = n % 10;
        t = n / 10;
        d3 = t % 10;
        t = t / 10;
        d2 = t % 10;
        d1 = t / 10;
        f = d2 * 1000 + d1 * 100 + d4 * 10 + d3;
        cout << f;
    }*/

    //3
    int a, b, c, d, e, f, g;
    cin >> a >> b >> c >> d >> e >> f >> g;
    if (a > b && a > c && a > d && a > e && a > f && a > g) cout << a;
    else if (b > a && b > c && b > d && b > e && b > f && b > g) cout << b;
    else if (c > a && c > b && c > d && c > e && c > f && c > g) cout << c;
    else if (d > a && d > c && d > b && d > e && d > f && d > g) cout << d;
    else if (e > a && e > c && e > d && e > d && e > f && e > g) cout << e;
    else if (f > a && f > c && f > d && f > e && f > e && f > g) cout << f;
    else cout << g;









}

    
        
            
        
    


        
    



        


        
    

    


    

















    







    
               

        

    
    
 
    
    
    













