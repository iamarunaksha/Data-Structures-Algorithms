#include<iostream>
using namespace std;

int main()
{
    int n,i,j; // Rhombus Pattern

    cout<<"\nEnter no. of rows : ";
    cin>>n;

    cout<<"\nThe required pattern is :\n"<<endl;

    for(i=1;i<=n;i++){                                     //Rows: 1 to n
        for(j=1;j<=n-i;j++){                              //Columns : Space ---> 1 to (n - Row No.)
            cout<<" ";                                   // for * ---> 1 to n
        }
        for(j=1;j<=n;j++){
            cout<<" *";
        }  
        cout<<endl;          
    }

    return 0;
}