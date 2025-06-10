#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int arabska;
    cin >> arabska;
    vector<pair<int, string>> liczby_rzymskie = 
    {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"}, 
        {1, "I"}
    };
    string rzymska = "";
    for(int i = 0; i < liczby_rzymskie.size(); ++i)
    {
        while(arabska >= liczby_rzymskie[i].first)
        {
            rzymska += liczby_rzymskie[i].second;
            arabska -= liczby_rzymskie[i].first;
        }
    }
    cout<<rzymska;
    return 0;
}