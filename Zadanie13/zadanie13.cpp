#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Uczen
{
    string imie, nazwisko;
    int ocena;
    public:
    Uczen(string i, string n, int o): imie(i), nazwisko(n), ocena(o) {}
    string get_imie() const
    {
        return imie;
    }
    string get_nazwisko() const
    {
        return nazwisko;
    }
    int get_ocena() const
    {
        return ocena;
    }
    void wyswietl_ucznia() const
    {
        cout << "Imie: " << imie << endl;
        cout << "Nazwisko: " << nazwisko << endl;
        cout << "Ocena: " << ocena << endl << endl;
    }
};

class BazaUczniow
{
    public:
    static vector<Uczen> wczytajUczniow()
    {
        vector<Uczen> uczniowie;
        int n = 0;
        while(true)
        {
            cout << "Podaj liczbe uczniow do wczytania: ";
            if(!(cin>>n) || n<=0)
            {
                cout<<"Liczba uczniow musi byc calkowita, wieksza od 0!\n";
                cin.clear();
                cin.ignore();
            }
            else
            {
                cin.ignore();
                break;
            }
        }
        string imie, nazwisko;
        int ocena;
        for (int i = 0; i < n; ++i)
        {
            cout << "\nUczen #" << i + 1 << endl;
            do
            {
                cout << "Imie: ";
                getline(cin, imie);
                if(imie.empty()) cout << "Imie nie moze byc puste!\n";
            } while (imie.empty());
            do
            {
                cout << "Nazwisko: ";
                getline(cin, nazwisko);
                if(nazwisko.empty()) cout << "Nazwisko nie moze byc puste!\n";
            } while (nazwisko.empty());
            while(true)
            {
                cout << "Ocena (1-6): ";
                if(!(cin >> ocena) || ocena < 1 || ocena > 6)
                {
                    cout<<"Niepoprawna ocena!"<<endl;
                    cin.clear();
                    cin.ignore();
                }
                else
                {
                    cin.ignore();
                    break;
                }
            }
            uczniowie.emplace_back(Uczen(imie, nazwisko, ocena));
        }
        return uczniowie;
    }
    static Uczen najlepszyUczen(const vector<Uczen>& uczniowie)
    {
        if(uczniowie.empty())
        {
            throw runtime_error("Brak uczniow w bazie");
        }
        int id_ucznia = 0;
        for(int i = 1; i < uczniowie.size(); ++i)
        {
            if(uczniowie[i].get_ocena() > uczniowie[id_ucznia].get_ocena())
            {
                id_ucznia = i;
            }
        }
        return uczniowie[id_ucznia];
    }
    static double sredniaOcen(const vector<Uczen>& uczniowie)
    {
        if(uczniowie.empty())
        {
            throw runtime_error("Brak uczniow w bazie");
        }

        double suma = 0;
        for(const auto& u : uczniowie)
        {
            suma += u.get_ocena();
        }
        return  suma / uczniowie.size();
    }
};

int main()
{
    try
    {
        vector<Uczen> uczniowie = BazaUczniow::wczytajUczniow();
        if(uczniowie.empty())
        {
            cout << "\nNie wczytano zadnych uczniow" << endl;
            return 0;
        }
        double srednia = BazaUczniow::sredniaOcen(uczniowie);
        cout << "\nSrednia ocen: " << srednia << endl;
        Uczen najlepszy = BazaUczniow::najlepszyUczen(uczniowie);
        cout << "\nNajlepszy uczen: " << endl;
        najlepszy.wyswietl_ucznia();
    }
    catch(const exception& e)
    {
        cout << "Blad: " << e.what() << endl;
    }
    return 0;
}