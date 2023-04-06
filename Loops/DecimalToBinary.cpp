#include<iostream>
#include<math.h>
using namespace std;

int main(){

    int num;
    cout<<"\nEnter the decimal no. that needs to be converted into binary : ";
    cin>>num;

    int i=0 , ans=0 , n=num;

    while(n != 0) {
        
        int bit = n & 1;

        ans = (bit * float(pow(10,i))) + ans;

        n = n >> 1;
        i++;

    }

    cout<<"\nBinary form of the decimal no. "<<num<<" is : "<<ans;
    cout<<" \n"<<endl;

    return 0;
}