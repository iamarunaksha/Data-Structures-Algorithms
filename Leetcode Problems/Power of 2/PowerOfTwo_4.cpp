#include<bits/stdc++.h>
using namespace std;

bool Power2(int num) {
    
    bitset<32> bits(num);
    return num>0 && bits.count() == 1;                          //counting set bits
                                                               //if n(set bits)=1 ---> power of 2
}

int main() {

     int n;
    cout<<"\nEnter the no. that needs to be checked : ";
    cin>>n;
    cout<<endl;

    cout.setf(ios :: boolalpha);                        //returns true/false instead of 0/1
    cout<<n<<" is a power of 2 : "<<Power2(n);
    cout<<"\n"<<endl;

    return 0;
}
