#include <iostream>
#include <vector>
using namespace std;
void bubblesort(vector<int>& tab)
{
    int n = tab.size();
    bool zamienione;

    for(int i = 0; i < n - 1; ++i)
    {
        zamienione = false;
        for(int j = 0; j < n - i - 1; ++j)
        {
            if(tab[j] > tab[j + 1])
            {
                swap(tab[j], tab[j + 1]);
                zamienione = true;
            }
        }
        if(!zamienione)
        {
            break;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> liczby(n);
    for(int i=0; i<n; i++)
    {
        cin>>liczby[i];
    }
    bubblesort(liczby);
    for(const auto& x : liczby)
    {
        cout << x << " ";
    }
    return 0;
}