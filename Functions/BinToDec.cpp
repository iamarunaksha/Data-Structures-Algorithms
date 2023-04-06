#include<iostream>
using namespace std;

int binaryToDecimal(int n) {

    int ans = 0;
    int base = 1;                              //for power of 2, initialising it with 1, as 2^0 = 1

    while(n>0) {

        int lastDigit = n%10;
        ans+= lastDigit*base;
        base *= 2;
        n /= 10;
    }

    return ans;
}

int main() {

    int b;
    cout<<"Enter the binary no. : ";
    cin>>b;

    cout<<"\nDecimal form of binary no. "<<b<<" is : "<<binaryToDecimal(b)<<endl;
    
    
    return 0;
}