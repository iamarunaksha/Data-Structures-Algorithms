#include<iostream>
using namespace std;

int main()
{
    int n,i,j; 

    cout<<"\nEnter no. of rows : ";
    cin>>n;

    cout<<"\nThe required pattern is :\n"<<endl;

    for(i=n;i>=1;i--){
        for(j=1;j<=n;j++){
            cout<<n*i+1-j<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    return 0;
}