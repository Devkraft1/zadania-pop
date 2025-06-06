#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
    string tekst;
    getline(cin, tekst);
    unordered_map<char, int> licznik;
    for(const auto& znak : tekst)
    {
        ++licznik[znak];
    }
    char najczestszyznak = '\0';
    int maksliczba = 0;
    for(const auto& para : licznik)
    {
        if(para.second>maksliczba)
        {
            najczestszyznak = para.first;
            maksliczba = para.second;
        }
    }
    if(maksliczba > 0)
    {
        cout << "Znak: \"" << najczestszyznak << "\" " << maksliczba << " razy" << endl;
    }
    else
    {
        cout << "Brak znakow";
    }
    return 0;
}