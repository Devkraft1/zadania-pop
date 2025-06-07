#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;
bool sprawdz(string s)
{
    unordered_set<char> cyfry;
    for(const auto& c : s)
    {
        cyfry.insert(c);
    }
    return cyfry.size() == 2;
}
int main()
{
    int n;
    cin >> n;
    cin.ignore();
    vector<string> liczby(n);
    for(int i = 0; i < n; ++i)
    {
        getline(cin, liczby[i]);
    }
    for(auto const& liczba : liczby)
    {
        if(sprawdz(liczba))
        {
            cout<<liczba<<" ";
        }
    }
    return 0;
}