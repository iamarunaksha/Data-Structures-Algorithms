#include<iostream>                                         
using namespace std;                                      // Difficult

int main() {

    int num;
    cout<<"\nEnter decimal no. : ";
    cin>>num;

    int n = num;
    int mask = 0;

    if(num==0){
        cout<<"\nThe complement of 0 is 1";
    }

    while(n!=0){
        mask = (mask << 1) | 1;                         //Using left-shift operator (multiply)
        n = n >> 1;                                    //Using right-shift operator
    }

    int ans = (~num) & mask;

    cout<<"\nThe complement of "<<num<<" is "<<ans;
    cout<<"\n"<<endl;

    return 0;
}