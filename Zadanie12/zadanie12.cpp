#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Kalkulator
{
    string tekst;
    int pozycja = 0;
    char sprawdz()
    {
        while(pozycja < (int)tekst.size() && isspace(tekst[pozycja])) ++pozycja;
        return (pozycja < (int)tekst.size()) ? tekst[pozycja] : '\0';
    }
    char get()
    {
        char ch = sprawdz();
        ++pozycja;
        return ch;
    }
    int liczba()
    {
        int wynik = 0;
        if (!isdigit(sprawdz())) 
        {
            throw runtime_error("Oczekiwana liczba naturalna");
        }
        while (isdigit(sprawdz())) 
        {
            wynik = wynik * 10 + (get() - '0');
        }
        return wynik;
    }
    int czynnik()
    {
        if(sprawdz() == '(')
        {
            get();
            int wynik = wyrazenie();
            if(get() != ')')
            {
                throw runtime_error("Brakuje nawiasu zamykajacego");
            }
            return wynik;
        }
        else return liczba();
    }
    int skladnik() 
    {
        int wynik = czynnik();
        while (true) 
        {
            char op = sprawdz();
            if (op == '*' || op == '/') 
            {
                get();
                int prawa = czynnik();
                if (op == '*') wynik *= prawa;
                else if (op == '/')
                {
                    if(prawa == 0) throw runtime_error("Dzielenie przez zero");
                    wynik /= prawa;
                }
            } 
            else break;
        }
        return wynik;
    }
    int wyrazenie() 
    {
        int wynik = skladnik();
        while (true) 
        {
            char op = sprawdz();
            if (op == '+' || op == '-') 
            {
                get();
                int prawa = skladnik();
                if (op == '+') wynik += prawa;
                else if (op == '-') wynik -= prawa;
            } 
            else break;
        }
        return wynik;
    }
    public:
    int oblicz(const string& rownanie) 
    {
        tekst = rownanie;
        pozycja = 0;
        int wynik = wyrazenie();
        if (sprawdz() != '\0') 
        {
            throw runtime_error("Nieoczekiwane znaki na koncu");
        }
        return wynik;
    }
};
int main()
{
    Kalkulator k;
    string rownanie;
    getline(cin, rownanie);
    try
    {
        int wynik = k.oblicz(rownanie);
        cout << wynik << endl;
    }
    catch(const exception& e)
    {
        cerr << "error: " << e.what() << endl;
    }
    return 0;
}