#include<iostream>
using namespace std;

int main()
{
    int n;                    // Printing all the digits of a +ive decimal no. from right to left
    cout<<"\nEnter any positive decimal no. : ";
    cin>>n;

    cout<<"\nAll the digits from right to left ---> ";

    while(n>0) {
        int rem = n % 10;
        cout<<rem;
        n=n/10;
    }

    cout<<"\n"<<endl;

    return 0;
}