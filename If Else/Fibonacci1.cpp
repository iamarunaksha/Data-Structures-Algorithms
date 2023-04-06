#include<iostream>
using namespace std;

int main()
{
    int n;                                      //Using only if else
    cout<<"\nEnter the no. of terms : ";
    cin>>n;

    cout<<"\nRequired Fibonacci Series : ";

    if(n==1) {
        cout<<"0\n";
    }
    else if(n==2) {
        cout<<"0 1\n";
    }
    else {
        int curr_f, a = 0, b = 1, i = 3;
        cout<<a<<" "<<b<<" ";
        while (i<=n) {
            curr_f = a + b;
            a=b;
            b=curr_f;
            i++;

            cout<<curr_f<<" ";
        }
        cout<<"\n";
    }

    cout<<endl;

    return 0;
}