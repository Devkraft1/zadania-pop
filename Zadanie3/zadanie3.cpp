#include <iostream>
using namespace std;

int obliczNWD(int a, int b)
{
    while(b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        int wynik = obliczNWD(a, b);
        cout << "NWD(" << a << ", " << b << ") = " << wynik << endl;
    }
    return 0;
}