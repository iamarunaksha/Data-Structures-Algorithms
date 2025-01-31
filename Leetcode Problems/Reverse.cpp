#include<iostream> 
#include <bits/stdc++.h>                                  
using namespace std;                                       

int main()
{
    int n;                                                  //Removing the trailing zeroes
    cout<<"\nEnter the no. : ";
    cin>>n;

    int reverse=0;
    while(n!=0){
        int lastdigit= n%10;

        if((reverse > INT_MAX/10) || (reverse < INT_MIN/10)) {
            return 0;
        }

        reverse= reverse*10 + lastdigit;
        n=n/10;
    }

    cout<<"\nThe reversed no. is : "<<reverse;


    return 0;
}