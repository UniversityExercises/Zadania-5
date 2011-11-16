#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    char znak;
    int litera=0, cyfra=0, aryt=0, wszystkie =0;

    ifstream dane;
    dane.open ("chars.txt");


    if(dane.good())
    {
        cout<<"otwarty bez bledu\n"<<endl;

        while(!dane.eof())
        {
            dane>>znak;

            wszystkie=wszystkie+1;

            if( (znak >='A'&& znak<='Z') || (znak >='a'&& znak<='z') )
            {
                litera=litera+1;
            }

            if( znak >='0'&& znak<='9' )
            {
                cyfra=cyfra+1;
            }

            if( znak =='*'|| znak=='/' || znak=='+' || znak=='-' )
            {
                aryt=aryt+1;
            }
        }
    }
    else
    {
        cout<<"blad otwarcia pliku\n";
    }
    dane.close();

    cout<<"wszystkie znaki: "<<wszystkie<<endl<<"ilosc liter: "<<litera<<endl;
    cout<<"ilosc znakow arytmetycznych: "<<aryt<<endl;
    cout<<"ilosc cyfr: "<<cyfra<<endl;

    return 0;
}
