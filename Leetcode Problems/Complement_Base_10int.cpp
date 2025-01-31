#include<iostream>                                         //Using XOR operator of 1 ten left-shift
using namespace std;

int main() {

    int num;
    cout<<"\nEnter decimal no. : ";
    cin>>num;

    int n = num;

    if(n==0) {
        cout<<"\nThe complement of 0 is 1";
    }
    
    int x=1;
    while(x<=n) {
        n = n ^ x;                                      //Performing XOR op.
        x = x << 1;                                    // Using left-shift operator
    }

    cout<<"\nThe complement of "<<num<<" is "<<n;

    cout<<"\n"<<endl;

    return 0;
}