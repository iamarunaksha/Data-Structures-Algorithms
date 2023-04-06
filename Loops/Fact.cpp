#include<iostream>
using namespace std;

int main()
{

    int n,i;
    cout<<"\nEnter any no. : ";
    cin>>n;

    cout<<"\nFactorial of "<<n<<" is : ";

    int fac=1;
    for(i=1;i<=n;i++){
        fac = fac*i;
    }

    cout<<fac;

    cout<<"\n"<<endl;

    return 0;
}