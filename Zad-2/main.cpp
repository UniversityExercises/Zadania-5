#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream plik_we;
    plik_we.open ("plik.txt");


    string line;
    int dlugosc=0;
    int line_counter = 0;


    while(!plik_we.eof())
    {
        getline (plik_we, line);
        dlugosc=dlugosc+line.length();

        line_counter= line_counter+1;
    }

    plik_we.close();

    plik_we.open("plik.txt");

    ofstream plik_wy;
    plik_wy.open("plik_analiza.txt");

    plik_wy<<"ilosc wierszy = "<<line_counter<<endl;
    plik_wy<<"ilosc znakow = "<<dlugosc<<endl;
    plik_wy<<"waga pliku = "<<dlugosc/1024.0<<" KB"<<endl<<endl;

    while(!plik_we.eof())
    {
        getline (plik_we, line);
        plik_wy<<line<<endl;

    }


    plik_wy<<"\n\nilosc wierszy = "<<line_counter<<endl;
    plik_wy<<"ilosc znakow = "<<dlugosc<<endl;
    plik_wy<<"waga pliku = "<<dlugosc/1024.0<<" KB"<<endl<<endl;

    plik_we.close();
    plik_wy.close();

    cout<<"analiza pliku zakonczona pomyslnie";


    return 0;
}
