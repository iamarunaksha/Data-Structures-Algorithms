#include<iostream>                                         //Not Optimal Sol.
using namespace std;                                      // Difficult

int main() {

    int num;
    cout<<"\nEnter decimal no. : ";
    cin>>num;

    if(num==0) {
        cout<<"Complement of 0 is = 1";
        return 0;
    }

    for(long i =1; i<=num; i*=2){
        num^=i;                                         //Using XOR of 1 with input num(decimal)
    }

    cout<<"Complement of the no. is = "<<num;

    return 0;
}