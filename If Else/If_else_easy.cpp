#include<iostream>
using namespace std;

int main()
{

int Savings;
cout<<"Enter your savings : "; // << - insertion operator 
cin>>Savings; // \ >> - extraction operator

cout<<"Your choice should be : ";

if(Savings>5000) {
    if(Savings>10000) {
        cout<<"Roadtrip with Deboleena";
    } else {
        cout<<"Shopping with Deboleena";
        }
}
else if(Savings>2000) {
    cout<<"Angana";
} else {
    cout<<"Friends";
}

return 0;

}

