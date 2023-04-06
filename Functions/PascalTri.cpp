#include<iostream>
using namespace std;

int fact(int n) {

    int factorial = 1;

    for(int i=2; i<=n; i++) {
        factorial*= i;
    }
    return factorial;
}

int main() {

    int n;
    cout<<"\nEnter the no. of rows : ";
    cin>>n;

    cout<<"\nRequired pattern : \n\n";

    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            cout<<fact(i)/(fact(j)*fact(i-j))<<" ";
        }
        cout<<endl;
    }

    return 0;
}