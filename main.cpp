#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

int main()
{
    //Wczytywanie pliku ze znakami do zamiany
    fstream char_list;
    char_list.open( "char_list.txt", ios::in);
    if( char_list.good() == true )
        cout << "char_list.txt\t\t\tOK!" << endl;
    else
    {
         cout << "char_list.txt\t\tERROR!" << endl;
         getch();
         return 0;
    }

    //Wczytanie listy znakow do zamiany i wyswietlenie jej
    string char_list_one;
    string char_list_two;
    getline( char_list, char_list_one );
    getline( char_list, char_list_two );
    cout<<endl;
    cout << "This:" << endl;
    cout << char_list_one << endl;
    cout<<endl;
    cout << "For this:" << endl;
    cout << char_list_two << endl;
    cout<<endl;
    char_list.close();

    //Wczytywanie pliku z lista plikow do edycji
    fstream lista;
    lista.open( "lista.txt", ios::in);
    if( lista.good() == true )
        cout << "lista\t\t\t\tOK!" << endl;
    else
    {
         cout << "lista\t\tERROR!" << endl;
         getch();
         return 0;
    }

    //Wczytanie kazdej nazwy pliku oddzielnie i edycja
    while( !lista.eof() )
    {
        int dlugosc_stringa;
        int dlugosc_char;
        dlugosc_char = char_list_one.length();
        string aktualna_nazwa;
        getline(lista, aktualna_nazwa);
        fstream aktualny_plik;
        aktualny_plik.open(aktualna_nazwa.c_str(), ios::in | ios::out);
        if( aktualny_plik.good() == true )
        {
            cout<<endl;
            cout << aktualna_nazwa << "\t\t\tOK!" << endl;

            string aktualna_linia_tekstu;
            string nowy;
            nowy = "new_";
            nowy = nowy + aktualna_nazwa.c_str();
            fstream nowy_plik( nowy.c_str(), ios::out );
            while( !aktualny_plik.eof() )
            {
                if( aktualny_plik.eof() == false )
                getline(aktualny_plik, aktualna_linia_tekstu);
                //cout << aktualna_linia_tekstu << endl;
                dlugosc_stringa = aktualna_linia_tekstu.length();
                for(int i=0; i<dlugosc_stringa; i++)
                    for(int j=0; j<dlugosc_char; j++)
                        if(aktualna_linia_tekstu[i]==char_list_one[j])
                            aktualna_linia_tekstu[i] = char_list_two[j];

                if( aktualny_plik.eof() == false )
                    nowy_plik << aktualna_linia_tekstu << endl;
                else
                    nowy_plik << aktualna_linia_tekstu;
                nowy_plik.flush();
                //cout << "Po zamianie: " << endl;
                //cout << aktualna_linia_tekstu << endl;
            }
            cout << nowy << "\t\t\tDone!" << endl;
            cout<<endl;
        }
        else
        {
            cout << aktualna_nazwa << "\t\t\tERROR!" << endl;
        }
        aktualny_plik.close();
    }
    cout << endl; cout << endl;
    cout << "Author: MrStPL";
    lista.close();
    getch();
    return 0;
}
