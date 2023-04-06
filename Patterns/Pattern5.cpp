#include<iostream>
using namespace std;

int main()
{
    int n,i,j; //Half Pyramid using numbers

    cout<<"\nEnter no. of rows : ";
    cin>>n;

    cout<<"\nThe required pattern is :\n"<<endl;

    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    return 0;
}