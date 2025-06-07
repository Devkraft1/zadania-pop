#include <iostream>
#include <cctype>
using namespace std;
bool porownaj(string st1, string st2)
{
    if(st1.length() != st2.length()) return false;
    int licznik[26] = {0};
    for(int i = 0; i < st1.length(); ++i)
    {
        char c1 = tolower(st1[i]);
        char c2 = tolower(st2[i]);
        if(c1 >= 'a' && c1 <= 'z')
        {
            licznik[c1 - 'a']++;
        }
        else
        {
            return false;
        }

        if(c2 >= 'a' && c2 <= 'z')
        {
            licznik[c2 - 'a']--;
        }
        else
        {
            return false;
        }
    }
    for(int i = 0; i < 26; ++i)
    {
        if(licznik[i] != 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string tekst1, tekst2;
    cin >> tekst1 >> tekst2;
    if(porownaj(tekst1, tekst2))
    {
        cout<<"Ciagi znakow sa anagramami";
    }
    else
    {
        cout<<"Ciagi znakow nie sa anagramami";
    }
    return 0;
}