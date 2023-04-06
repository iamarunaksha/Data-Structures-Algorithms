#include<iostream>                                      // Using a different method
#include<cmath>
using namespace std;

int main()
{
    int n;
    cout<<"\nEnter the no. : ";
    cin>>n;

    bool flag=0;

    int i;
    for(i=2;i<=sqrt(n);i++){
        if(n%i==0){
            cout<<"\nThe no. "<<n<<" is not prime"<<endl;
            flag=1;
            break;
        }
    }

    if(flag==0){
        cout<<"\nThe no. "<<n<<" is prime"<<endl;
    }

    return 0;
}