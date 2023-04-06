#include<iostream>
using namespace std;

int decimalToBin(int n) {                                               //not understanding this approach

    int ans = 0;
    int base = 1;                              

    while(base <= n) {

        base *= 2;
    }   
    
        base /= 2;
    
    while(base > 0) {
        
        int lastDigit = n/base;
        n -= lastDigit * base;
        base /= 2;
        ans = ans*10 + lastDigit;
    }

    return ans;
}

int main() {

    int d;
    cout<<"\nEnter the decimal no. : ";
    cin>>d;

    cout<<"\nBinary form of decimal no. "<<d<<" is : "<<decimalToBin(d)<<endl;
    cout<<endl;
    
    return 0;
}