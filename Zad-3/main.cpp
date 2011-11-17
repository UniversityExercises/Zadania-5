#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    cout<<"podaj nazwe pliku\n";
    string nazwa;
    cin>>nazwa;
    getchar();

    ofstream dane;
    dane.open(nazwa.c_str());

    cout<<"podaj ile chcesz wprowadzic linijek tekstu:"<<endl;
    int n;
    cin>>n;
    string linia;

    for (int i=0; i<n; i++)
    {
        cin>>linia;
        dane<<linia<<endl;
    }

    dane.close();

    ifstream dane_czyt;
    dane_czyt.open ( nazwa.c_str() );

    string reszta_linii;

    cout<<"Zawartosc pliku result.txt :"<<endl;

    for (int i=0; i<n; i++)
    {
        getline (dane_czyt, reszta_linii);
        if ( ( reszta_linii[0]>='A' && reszta_linii[0]<='Z' ) && reszta_linii.length() <=10 )
        {
            ofstream wyniki;
            wyniki.open ("results.txt");
            wyniki<<reszta_linii<<endl;
            cout<<reszta_linii<<endl;
        }

    }


    return 0;
}
