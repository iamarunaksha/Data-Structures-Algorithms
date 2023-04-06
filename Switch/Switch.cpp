#include<iostream>
using namespace std;

int main()
{
    
    char button;
    cout<<"\nPress the preferred button : ";
    cin>>button;

    switch (button)
    {
    case 'a':
        cout<<"\nHello"<<endl;
        break;

    case 'b':
        cout<<"\nNamaste"<<endl;
        break;

    case 'c':
        cout<<"\nHola"<<endl;
        break;

    case 'd':
        cout<<"\nSalut"<<endl;
        break;

    case 'e':
        cout<<"\nCiao"<<endl;
        break;

    default:
        cout<<"\nI am still learning !!"<<endl;
        break;
    }
    
    return 0;
}