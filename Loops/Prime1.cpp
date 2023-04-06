#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"\nEnter the no. : ";
    cin>>n;

    int i;
    for(i=2; i<n; i++){
        if(n%i==0){
            cout<<"\nThe no. is not prime";
            break;
        }
    }
    if(i==n){
        cout<<"\nThe no. is prime";
    }

}