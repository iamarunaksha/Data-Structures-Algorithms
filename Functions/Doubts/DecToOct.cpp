#include<iostream>
using namespace std;

int decimalToOct(int n) {                                              

    int ans = 0;
    int base = 1;                              

    while(base <= n) {

        base *= 8;
    }   
    
        base /= 8;
    
    while(base > 0) {
        
        int lastDigit = n/base;
        n -= lastDigit * base;
        base /= 8;
        ans = ans*10 + lastDigit;
    }

    return ans;
}

int main() {

    int d;
    cout<<"\nEnter the decimal no. : ";
    cin>>d;

    cout<<"\nOctal form of decimal no. "<<d<<" is : "<<decimalToOct(d)<<endl;
    cout<<endl;
    
    return 0;
}