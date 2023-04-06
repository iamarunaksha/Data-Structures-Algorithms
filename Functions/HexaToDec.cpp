#include<bits/stdc++.h>
using namespace std;

int hexaToDecimal(string n) {

    int ans = 0;
    int base = 1;                              //for power of 16, initialising it with 1, as 8^0 = 1
    
    for(int i = n.size()-1; i >= 0; i--) {

        if(n[i] >= '0' && n[i] <= '9') {

            ans += base*(n[i]-'0');            // string stores integer as input as char type, so -'0' is done
        }
        else if(n[i] >= 'A' && n[i] <= 'F') {

            ans+= base*(n[i]-'A'+10);
        }

        base *= 16; 
    }

    return ans;
}

int main() {

    string h;
    cout<<"\nEnter the hexadecimal no. : ";
    cin>>h;

    cout<<"\nDecimal form of hexadecimal no. "<<h<<" is : "<<hexaToDecimal(h)<<endl;
    
    
    return 0;
}