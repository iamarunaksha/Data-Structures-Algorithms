#include <iostream>
using namespace std;

int main() {

    int n;
    cout<<"\nEnter the upper limit : ";
    cin>>n;

    int i=2;
    int sum=0;

    while(i<=n){
        sum+= i;
        i+= 2;
    }

    cout<<"\nSum of even no.s upto the upper limit is : "<<sum;

    return 0;
}