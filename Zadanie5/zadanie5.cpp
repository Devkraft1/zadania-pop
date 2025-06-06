#include <iostream>
#include <string>
using namespace std;

int main()
{
    string tekst;
    int n;
    getline(cin, tekst);
    cin >> n;

    n %= 26;
    if(n<0)
    {
        n+=26;
    }
    string szyfr;
    for(const auto& znak : tekst)
    {
        if(isalpha(znak))
        {
            char start = isupper(znak) ? 'A' : 'a';
            char zaszyfrowany_znak = (znak - start + n) % 26 + start;
            szyfr += zaszyfrowany_znak;
        }
        else
        {
            szyfr += znak;
        }
    }
    cout<<szyfr;
    return 0;
}