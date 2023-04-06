#include<iostream>
using namespace std;                                // Pascal Triangle element at n = (Row-1)th row & r = (Col-1)th column

long long nCr(int n, int r) {
    
    long long res = 1;                          // T.C --> O(r)   S.C --> O(1)

    for (int i = 0; i < r; i++) {
        
        res *= (n-i);
        res /= (i+1);
    }

    return res;
}

int main() {

    long long n, r;

    cout<<"\nEnter the value of n : ";
    cin>>n;

    cout<<"\nEnter the value of r : ";
    cin>>r;

    cout<<"\nValue of "<<n<<"C"<<r<<" is : "<<nCr(n,r)<<endl;

    return 0;
}