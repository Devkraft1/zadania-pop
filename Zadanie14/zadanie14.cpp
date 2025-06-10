#include <iostream>
#include <string>
#include <set>
#include <unordered_map>
using namespace std;

class Tekst
{
    public:
    static string usuninterpunkcje(string tekst)
    {
        string nowy_tekst = "";
        for(const auto& znak : tekst)
        {
            if(znak!='.' && znak != ',' && znak != '!' && znak != '?' && znak != ':' && znak != '"' && znak != ';')
            {
                nowy_tekst += tolower(znak);
            }
        }
        return nowy_tekst;
    }

    static int policzWyrazyRozne(string tekst)
    {
        tekst = usuninterpunkcje(tekst);
        set<string> unikalne_wyrazy;
        string wyraz = "";
        for(const auto& znak : tekst)
        {
            if(znak != ' ')
            {
                wyraz += znak;
            }
            else
            {
                if(!wyraz.empty())
                {
                    unikalne_wyrazy.insert(wyraz);
                    wyraz = "";
                }
            }
        }
        if(!wyraz.empty()) unikalne_wyrazy.insert(wyraz);
        return unikalne_wyrazy.size();
    }
    static string najczestszeslowo(string tekst)
    {
        tekst = usuninterpunkcje(tekst);
        unordered_map<string,int> ilosc_wyrazow;
        string wyraz = "";
        for(const auto& znak : tekst)
        {
            if(znak != ' ')
            {
                wyraz += znak;
            }
            else
            {
                if(!wyraz.empty())
                {
                    ilosc_wyrazow[wyraz]++;
                    wyraz = "";
                }
            }
        }
        if(!wyraz.empty()) ilosc_wyrazow[wyraz]++;
        string najczestsze = "";
        int max_ilosc = 0;
        for(const auto& para : ilosc_wyrazow)
        {
            if(para.second > max_ilosc)
            {
                max_ilosc = para.second;
                najczestsze = para.first;
            }
        }
        return najczestsze;
    }
};
int main()
{
    string tekst;
    getline(cin, tekst);
    cout<<Tekst::usuninterpunkcje(tekst)<<endl;
    cout<<Tekst::policzWyrazyRozne(tekst)<<endl;
    cout<<Tekst::najczestszeslowo(tekst)<<endl;
    return 0;
}