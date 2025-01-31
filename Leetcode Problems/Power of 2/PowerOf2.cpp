#include<iostream>                                      //using floor & ceil functions
#include<math.h>
using namespace std;

int main() {

    int n;
    cout<<"\nEnter the no. that needs to be checked : ";
    cin>>n;

    if(n==0) cout<<"\nFalse : 0 is not a power of 2";

    if(ceil(log2(n)) == floor(log2(n))) {                                        //if n is not a power of 2 then its log will be in decimal
        cout<<"\nTrue : "<<n<<" is a power of 2";
    }
    else {
        cout<<"\nFalse : "<<n<<" is not a power of 2";
    }

    cout<<"\n"<<endl;

    return 0;
}