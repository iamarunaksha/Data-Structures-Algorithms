#include<iostream>
#include<math.h>
using namespace std;

int main(){

    int num;
    cout<<"\nEnter the binary no. that needs to be converted into decimal : ";
    cin>>num;

    int i=0 , ans=0 , n=num;

    while(n!=0){

        int digit = n % 10;

        if( digit == 1) {
            ans += pow(2, i);
        }

        n = n/10;
        i++;


    }

    cout<<"\nDecimal form of the binary no. "<<num<<" is : "<<ans;
    cout<<" \n"<<endl;

    return 0;
}