#include <iostream>
#include <cmath>
using namespace std;
bool czyDoskonala(int n)
{
    if(n < 2) return false;
    int suma = 1;
    for(int i = 2; i <= sqrt(n); i++)
    {   
        if(n % i == 0)
        {
            suma += i;
            int dzielnik2 = n / i;
            if(dzielnik2 != i)
            {
                suma += dzielnik2;
            }
        }
    }
    return suma == n;
}
int main()
{
    int n;
    cin >> n;
    if(czyDoskonala(n))
    {
        cout << n << " jest liczba doskonala" << endl;
    }
    else
    {
        cout << n << " nie jest liczba doskonala" << endl;
    }
    return 0;
}