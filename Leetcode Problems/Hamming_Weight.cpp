#include<iostream>   
#include<math.h>                                                 //Calculate no. of 1 bits in binary string
using namespace std;

int main() {

    int num;
    cout<<"\nEnter a binary no. : ";
    cin>>num;

    int i=0 , res=0 ;

    while(num!=0){                                             //For Binary to Decimal Conversion

        int digit = num % 10;

        if( digit == 1) {
            res = res + pow(2, i);
        }

        num /= 10;
        i++;

    }

    int ans = 0;                              //Start from here if input is already being taken in decimal

    while(res!=0) {                                      //Taking res as decimal input |num (binary) ---> res (decimal)
        if(res&1) {
            ans++;
        }
        res = res >> 1;
    }

    cout<<"\nThe no. of 1 bits = "<<ans;
    cout<<"\n"<<endl;

    return 0;
}