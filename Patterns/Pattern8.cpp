#include<iostream>
using namespace std;

int main()
{
    int n,i,j; //Inverted triangle

    cout<<"\nEnter no. of rows : ";
    cin>>n;

    cout<<"\nThe required pattern is :\n"<<endl;


    for(i=1;i<=n;i++){                                          //Rows : 1 to n                                                        
        for(j=1;j<=n+1-i;j++){                                 //Columns : 1 to (n+1 - Row No.)                                                         
            cout<<j<<" ";                                     //Elements : Column No.
        }
        cout<<"\n";
    }                                                            

    cout<<"\n";

    return 0;
}