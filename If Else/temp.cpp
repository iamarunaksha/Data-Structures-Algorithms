#include <iostream>                 //option at the beginning to choose from C or F
using namespace std;

int main() {

    int n;
    cout<<"\nEnter 1 for input of degree celsius or 2 for input of degree fahrenheit : ";
    cin>>n;

    float temp;
    cout<<"\nEnter value of temperature : ";
    cin>>temp;

    if(n==1){

        float fahr;
        fahr = temp*9/5 + 32;
        cout<<"\n"<<temp<<" degree celsius = "<< fahr<<" degree fahrenheit";
    }

    else if(n==2){

        float cel;
        cel= (temp-32)*5/9;
        cout<<"\n"<<temp<<" degree fahrenheit = "<< cel<<" degree celsius";
    }

    else {
        cout<<"Choice is invalid !";
    }

    return 0;
}