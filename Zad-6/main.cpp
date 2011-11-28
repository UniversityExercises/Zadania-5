#include <iostream>

using namespace std;

double absolute (double x)
{
    if (x>=0)
    {
        return x;
    }
    else
    {
        x=-x;
        return x;
    }
}

double fahrenheitToCelsius (double Tf)
{
    double Tc;
    Tc=5.0/9.0*(Tf-32);
    return Tc;
}


double power (double x, int y)
{
    if(y==0)
    {
        return 1;
    }


    if(y>0)
    {
        double result=1;

        for (int i=0; i<y; i++)
        {
            result=result*x;
        }
        return result;
    }

    if(y<0)
    {
        x=1.0/x;
        y=-y;
        double result=1;

        for (int i=0; i<y; i++)
        {
            result=result*x;
        }
        return result;
    }
}

void printPyramid (int h)
{
    for (int i=0; i<h; i++)
    {
        for (int j=0; j<h-i-1; j++)
        {
            cout<<" ";
        }

        for (int k=0; k<2*i+1; k++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}

int main()
{
    cout<<"1-absolute\n2-fahrenheitToCelsius\n3-power\n4-printPyramid\n";
    int wybor;
    do
    {
        cin>>wybor;
    }
    while(wybor!=1 && wybor!=2 && wybor!=3 && wybor!=4  );

    //absolute

    if(wybor==1)
    {
        double liczba;
        cout<<"wprowadz liczbe"<<endl;

        cin>>liczba;
        cout<<absolute(liczba)<<endl;
    }

    //fahrenheitToCelsius
    if(wybor==2)
    {
        double temperatura;
        cout<<"wprowadz temperature w st Fahrenheita:"<<endl;
        cin>>temperatura;
        cout<<fahrenheitToCelsius (temperatura)<<endl;
    }

    //power
    if(wybor==3)
    {
        cout<<"wprowadz podstawe x (double) i wykladnik y (int):"<<endl;
        double x, y;
        cin>>x;
        cin>>y;
        cout<<power(x,y)<<endl;
    }

    //printPyramid
    if(wybor==4)
    {
        int wys;
        cout<<"wprowadz wysokosc piramidy"<<endl;
        cin>>wys;
        printPyramid(wys);
    }
    return 0;
}
