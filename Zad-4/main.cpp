#include <iostream>
#include <fstream>
#include <math.h>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Point
{
    int x;
    int y;
    int lp;
    double odl;
} punkt;

int main()
{
    cout<<"1 - reczne wybieranie punktow"<<endl;
    cout<<"2 - losowe generowanie punktow"<<endl;

    int wybor;

    do
    {
        cin>>wybor;
    }
    while(wybor!=1 && wybor!=2);

    string file_name;
    cout<<"\nwprowadz nazwe pliku"<<endl;
    string sciezka="Data/";
    cin>>file_name;
    file_name=sciezka+file_name;

    ofstream temp_file;
    temp_file.open(file_name.c_str());

    int licznik=0;

    if(wybor==1)
    {


        do
        {
            licznik=licznik+1;
            punkt.lp=licznik;
            temp_file<<punkt.lp<<",";
            cout<<"wprowadz wsp. x punktu "<<licznik<<":"<<endl;
            cin>>punkt.x;
            temp_file<<punkt.x<<",";
            cout<<"wprowadz wsp. y punktu "<<licznik<<":"<<endl;
            cin>>punkt.y;
            cout<<endl;
            temp_file<<punkt.y;
            temp_file<<endl;
        }
        while (punkt.x!=0 || punkt.y!=0);

    }

    if (wybor==2)
    {
        srand(time(0));
        do
        {
            licznik=licznik+1;
            punkt.lp=licznik;
            temp_file<<punkt.lp<<",";
            //okreslam zakres losowanych wsp. x
            punkt.x=(rand()/double(RAND_MAX))*20.0-10;
            cout<<"wsp. x punktu "<<licznik<<": "<<punkt.x<<endl;
            temp_file<<punkt.x<<",";
            //okreslam zakres losowanych wsp. y
            punkt.y=(rand()/double(RAND_MAX))*20.0-10;
            cout<<"wsp. y punktu "<<licznik<<": "<<punkt.y<<endl;
            temp_file<<punkt.y;
            temp_file<<endl;
        }
        while (punkt.x!=0 || punkt.y!=0);
    }

    cout<<endl;
    temp_file.close();



    ifstream temp_file_read;
    temp_file_read.open(file_name.c_str());


    ofstream result;
    result.open("Data/result.txt");
    char znak;
    int suma=0;

    while(!temp_file_read.eof())
    {
        temp_file_read>>punkt.lp;
        temp_file_read>>znak;
        temp_file_read>>punkt.x;
        temp_file_read>>znak;
        temp_file_read>>punkt.y;

        if(punkt.y==0 && punkt.x!=0)
        {
            result<<punkt.lp<<znak<<punkt.x<<znak<<punkt.y<<endl;
            suma=suma+1;
        }
    }
    temp_file_read.close();
    temp_file_read.open(file_name.c_str());

    while(!temp_file_read.eof())
    {

        temp_file_read>>punkt.lp;
        temp_file_read>>znak;
        temp_file_read>>punkt.x;
        temp_file_read>>znak;
        temp_file_read>>punkt.y;

        if(punkt.x==0 && punkt.y!=0)
        {
            result<<punkt.lp<<znak<<punkt.x<<znak<<punkt.y<<endl;
            suma=suma+1;
        }
    }
    result.close();
    temp_file_read.close();

    ifstream result_read;
    result_read.open ("Data/result.txt");



    // z gory definiuje rozmiar tablicy.
    // ilosc wylosowanych punktow nie moze przekroczyc tej wartosci

    Point tablica[1000];

    for (int i=0; i<suma; i++)
    {
        result_read>>tablica[i].lp;
        result_read>>znak;
        result_read>>tablica[i].x;
        result_read>>znak;
        result_read>>tablica[i].y;

        tablica[i].odl= sqrt( ( (tablica[i].x)*(tablica[i].x) )+( (tablica[i].y) *(tablica[i].y) ) );
    }

    result_read.close();
    for(int i=0; i<suma-1; i++)
    {
        int i_min=i;
        for(int j=i+1; j<suma; j++)
        {
            if(tablica[j].odl < tablica[i_min].odl)
            {
                i_min=j;
            }
        }

        Point temp;
        temp=tablica[i];
        tablica[i]=tablica[i_min];
        tablica[i_min]=temp;
    }

    cout<<"wyswietlam posortowane lp. punktow:"<<endl;

    for (int i=0; i<suma; i++)
    {
        cout<<tablica[i].lp<<endl;
    }
    return 0;
}
