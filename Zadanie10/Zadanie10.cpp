#include <iostream>
#include <unordered_map>
#include <time.h>
#include <string>
using namespace std;

int main()
{
    unordered_map<int, int> losy;
    srand(time(NULL));
    int wylosowana;
    for(int i = 0; i < 1000; ++i)
    {
        wylosowana=rand()%6+1;
        losy[wylosowana]++;
    } 
    for(int i = 1; i <= 6; ++i)
    {
        cout << i << ": " << losy[i] << endl;
    }
    int najczestsza = losy[1];
    for(int i = 2; i <= 6; ++i)
    {
        if(losy[i]>najczestsza)
        {
            najczestsza=losy[i];
        }
    }
    string wynik_najczestsza = "Najczestsza: ";
    for(const auto& para : losy)
    {
        if(para.second == najczestsza)
        {
           wynik_najczestsza += (to_string(para.first) + " "); 
        }
    }
    cout << wynik_najczestsza << endl;
    int najrzadsza = losy[1];
    for(int i = 2; i <= 6; ++i)
    {
        if(losy[i]<najrzadsza)
        {
            najrzadsza=losy[i];
        }
    }
    string wynik_najrzadsza = "Najrzadsza: ";
    for(const auto& para : losy)
    {
        if(para.second == najrzadsza)
        {
            wynik_najrzadsza += (to_string(para.first) + " ");
        }
    }
    cout << wynik_najrzadsza << endl;
    for(int i = 1; i <= 6; ++i)
    {
        float procent = losy[i]/10.0;
        cout << i << ": " << procent << "%" <<endl;
    }
    return 0;
}