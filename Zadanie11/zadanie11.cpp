#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> wysokosc(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> wysokosc[i];
    }
    int max_pojemnosc = 0;
    int lewy = 0;
    int prawy = n - 1;
    while(lewy < prawy)
    {
        int wysokosc_min = min(wysokosc[lewy], wysokosc[prawy]);
        int szerokosc = prawy - lewy;
        int pole = wysokosc_min * szerokosc;
        max_pojemnosc = max(max_pojemnosc, pole);
        if (wysokosc[lewy] < wysokosc[prawy]) ++lewy;
        else --prawy;
    }
    cout<<max_pojemnosc;
    return 0;
}