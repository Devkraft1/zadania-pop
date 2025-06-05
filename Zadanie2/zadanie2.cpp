#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int oryginalna = n;
    int odwrocona = 0;
    
    while(n>0)
    {
        int cyfra = n % 10;
        odwrocona = odwrocona * 10 + cyfra;
        n/=10;
    }
    if(odwrocona == oryginalna)
    {
        cout << oryginalna << " jest palindromem";
    }
    else
    {
        cout << oryginalna << " nie jest palindromem";
    }
    return 0;
}