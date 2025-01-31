#include<bits/stdc++.h>                                             
using namespace std;

bool Power2(int n) {
        
        if (n == 0) return false;

        while (n != 1) {
             if (n%2 != 0)                                          // n is odd
                return false;
            n /= 2;                                                // for a power of 2 it eventually results 1
         }

     return true;

    }

int main() {
    
    int num;

    cout<<"\nEnter the no. that needs to be checked : ";
    cin>>num;
    cout<<endl;

    cout.setf(ios :: boolalpha);                        //returns true/false instead of 0/1
    cout<<num<<" is a power of 2 : "<<Power2(num);
    cout<<"\n"<<endl;

    return 0;
}