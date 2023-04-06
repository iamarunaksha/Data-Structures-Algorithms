#include<iostream>
using namespace std;

int main()
{

    char button;
    cout<<"\nPress the preferred button : ";
    cin>>button;

    if (button == 'a'){
        cout<<"\nHello"<<endl;
    }
    else if (button == 'b'){
        cout<<"\nNamaste"<<endl;
    }
    else if (button == 'c'){
        cout<<"\nHola"<<endl;
    }
    else if (button == 'd'){
        cout<<"\nSalut"<<endl;
    }
    else if (button == 'e'){
        cout<<"\nCiao"<<endl;
    }
    else{
        cout<<"\nI am still learning"<<endl;
    }
    
    return 0;
}