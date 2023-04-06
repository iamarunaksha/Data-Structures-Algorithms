#include<iostream>   
#include<math.h>                                                
using namespace std;

int SetBit(int n) {

    int ans = 0;                             

    while(n!=0) {                                     
        if(n&1) {
            ans++;
        }
        n >>= 1;
    }
    return ans;
}

int main() {

    int n1;
    cout<<"\nEnter the 1st no. : ";
    cin>>n1;

    int n2;
    cout<<"\nEnter the 2nd no. : ";
    cin>>n2;

    cout<<"\nThe no. of 1 bits in "<<n1<<" = "<<SetBit(n1);
    
    cout<<"\n\nThe no. of 1 bits in "<<n2<<" = "<<SetBit(n2);
    
    cout<<"\n"<<endl;

    return 0;
}