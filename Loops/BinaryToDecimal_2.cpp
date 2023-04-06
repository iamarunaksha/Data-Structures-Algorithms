#include<iostream>
using namespace std;

int main(){

    int num;
    cout<<"\nEnter the binary no. that needs to be converted into decimal : ";
    cin>>num;

    int base=1 , ans=0 , n=num;

    while(n!=0) {

        int last_digit = n % 10 ;
        n /= 10;
        ans += last_digit * base;
        base *= 2; 
    }

    cout<<"\nDecimal form of the binary no. "<<num<<" is : "<<ans;
    cout<<" \n"<<endl;

    return 0;
}