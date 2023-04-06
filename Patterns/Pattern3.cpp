#include<iostream>
using namespace std;

int main()
{
    int n,i,j; //Inverted half pyramid

    cout<<"\nEnter no. of rows : ";
    cin>>n;

    cout<<"\nThe required pattern is :\n"<<endl;

    for(i=n;i>=1;i--){
        for(j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    
    return 0;
}