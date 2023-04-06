#include<iostream>
using namespace std;

//Function Signature
void printCounting(int num) {

    cout<<"\nNo.s are : ";

    //Function Body 
    for(int i=1; i<=num; i++) {
        cout<< i << " ";
    }
    cout<<endl;
}

int main() {

    int n;
    cout<<"\nEnter the no. upto which counting is to be done (from 1) : ";
    cin >> n;

    //function Call
    printCounting(n);

    cout<<endl;

    return 0;
}