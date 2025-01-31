#include<iostream>
using namespace std;

// 0-> false (default)
//1-> true

bool Power2(int num) {
    return num>0 && !(num&(num-1));                        // if n & (n-1) = 0 ---> then n is power of 2
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