#include<iostream>
using namespace std;

int octalToDec(int n) {

    int ans = 0;
    int base = 1;                              //for power of 8, initialising it with 1, as 8^0 = 1

    while(n>0) {

        int lastDigit = n%10;
        ans+= lastDigit*base;
        base *= 8;
        n /= 10;
    }

    return ans;
}

int main() {

    int o;
    cout<<"\nEnter the octal no. : ";
    cin>>o;

    cout<<"\nDecimal form of octal no. "<<o<<" is : "<<octalToDec(o)<<endl;
    cout<<endl;
    
    return 0;
}