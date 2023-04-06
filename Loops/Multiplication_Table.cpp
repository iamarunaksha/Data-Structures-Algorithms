#include<iostream>
using namespace std;

int main() {

    int n;
    cout<<"\nEnter the no. whose multiplication table is to be displayed : ";
    cin>>n;

    int l;
    cout<<"\nEnter the no. upto which table is to be displayed : ";
    cin>>l;

    cout<<"\nMultiplication table of "<<n<<" upto "<<l<<" terms : "<<endl;

    for(int i=1; i<=l; i++) {
        cout<<n*i<<endl;
    }

    return 0;
}