#include<iostream>                                              
using namespace std;

int main()
{
    int n; // No. right-angled triangle

    cout<<"\nEnter no. of rows : ";
    cin>>n;

    cout<<"\nThe required pattern is :\n"<<endl;

    int i=1;

    while(i<=n){

        int j=1;
        while(j<=n){
            cout<<n-j+1<<" ";
            j+=1;
        }
        cout<<endl;
        i+=1;
    }

       cout<<endl;

    return 0;
}