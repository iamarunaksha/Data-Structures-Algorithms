#include<iostream>
using namespace std;

int factorial(int n){
    if (n<=1){
        return 1;
    }
    return n * factorial(n-1);
}

int main() {

    int a;
    cout<<"\nEnter a number whose factorial is desired : ";
    cin>>a;

    cout<<"The factorial of "<<a<< " is : "<<factorial(a)<<endl;

    return 0;
}