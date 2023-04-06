#include<iostream>
using namespace std;

int main()
{
    int n;                                  //Reverse counting square pattern

    cout<<"\nEnter no. of rows : ";
    cin>>n;

    cout<<"\nThe required pattern is :\n"<<endl;

    int i=1;
    int temp=(n*n);

    while(i<=n){

        int j=1;
        while (j<=n){
            cout<<temp<<" ";
            temp-=1;
            j+=1;
        }

        cout<<endl;
        i+=1; 
    }

        return 0;
}