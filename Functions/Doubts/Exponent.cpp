#include<iostream>
using namespace std;

int power(int baseNum, int powNum) {

    int result = 1;

    for(int i=0; i<powNum; i++)
        result *= baseNum;

    return result;
}

int main() {

    int base;
    cout<<"\nEnter the base no. : ";
    cin>>base;

    int expo;
    cout<<"\nEnter the power factor : ";
    cin>>expo;

    cout<<"\n";

    cout<<base<<" raise to the power "<<expo<<" is : "<<power(base,expo);

    return 0;
}