#include<bits/stdc++.h>
using namespace std;

string decimalToHexa(int n) {                                               //not understanding this approach

    string ans = "";
    int base = 1;                              

    while(base <= n) {

        base *= 16;
    }   
    
        base /= 16;
    
    while(base > 0) {
        
        int lastDigit = n/base;
        n -= lastDigit * base;
        base /= 16;
        
        if(lastDigit <= 9)
        ans = ans + to_string(lastDigit);

        else {
            char c = 'A' + lastDigit - 10;
            ans.push_back(c);
        }
    }

    return ans;
}

int main() {

    int d;
    cout<<"\nEnter the decimal no. : ";
    cin>>d;

    cout<<"\nHexadecimal form of decimal no. "<<d<<" is : "<<decimalToHexa(d)<<endl;
    cout<<endl;
    
    return 0;
}