#include<iostream>
using namespace std;

int main()
{
    int n,i,j; // Number Triangle Pattern

    cout<<"\nEnter no. of rows : ";
    cin>>n;

    cout<<"\nThe required pattern is :\n"<<endl;

    for(i=1;i<=n;i++) {                                           //Rows : 1 to n
        for(j=1;j<=n-i;j++){                                    //Columns : Space ---> 1 to (n - Row No.)
            cout<<" ";                                         // for * ---> 1 to Row No. 
        }                                                     //Elements : Column No. followed by space
        for(j=1;j<=i;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}