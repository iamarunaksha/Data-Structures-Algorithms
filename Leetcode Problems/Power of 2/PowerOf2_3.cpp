#include<iostream>                                      //using bit manipulation
using namespace std;

bool Power2(int n) {
    
    if(n==0)
        return false;
    
    while(n>1 && (n&1)==0)
        n>>=1;                                  //using right shift on n
    
    return n==1?true:false;
}

int main() {
    
    int num;
    cout<<"\nEnter the no. that needs to be checked : ";
    cin>>num;
    cout<<endl;

    cout.setf(ios :: boolalpha);                        //returns true/false instead of 0/1
    cout<<num<<" is a power of 2 : "<<Power2(num);
    cout<<"\n"<<endl;

    return 0;
}