#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int wybor;
    do
    {
        cout<<"\nMENU:\n1-drukuj\n2-wyjscie\n";

        do
        {
            cin>>wybor;
        }
        while(wybor!=1 && wybor!=2);

        if(wybor==1)
        {
            string sciezka;
            cout<<"wprowadz sciezke pliku:"<<endl;
            cin>>sciezka;

            ifstream plik_we;
            plik_we.open(sciezka.c_str());

            if(!plik_we.good())
            {
                cout<<"blad otwarcia pliku"<<endl;
                continue;
            }
            else
            {
                string linia;
                while(!plik_we.eof())
                {
                    getline(plik_we, linia);
                    cout<<linia<<endl;
                }
                plik_we.close();
            }
        }
    }
    while(wybor!=2);

    return 0;
}
