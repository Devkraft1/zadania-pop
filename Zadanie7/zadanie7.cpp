#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
bool porownaj(const vector<int>& tab1, const vector<int>& tab2)
{
    if(tab1.size() != tab2.size()) return false;
    unordered_map<int, int> licznik1, licznik2;
    for(const auto& x : tab1) licznik1[x]++;
    for(const auto& x : tab2) licznik2[x]++;
    return licznik1 == licznik2;
}
int main()
{
    vector<int> tab1, tab2;
    int n1, n2, liczba;
    cin >> n1;
    for(int i = 0; i < n1; ++i)
    {
        cin>>liczba;
        tab1.push_back(liczba);
    }
    cin >> n2;
    for(int i = 0; i < n2; ++i)
    {
        cin >> liczba;
        tab2.push_back(liczba);
    }
    if(porownaj(tab1, tab2))
    {
        cout << "zawieraja te same elementy";
    }
    else
    {
        cout << "nie zawieraja tych samych elementow";
    }
    return 0;
}