#include<iostream>                                              //Important
using namespace std;

int main()
{
    int n,i,j; // Pallindromic Pattern

    cout<<"\nEnter no. of rows : ";
    cin>>n;

    cout<<"\nThe required pattern is :\n"<<endl;

    for(i=1;i<=n;i++){                                          //Rows : 1 to m
        for(j=1;j<=n-i;j++){                                   //Columns : 3 parts :- for space ---> 1 to (n-Row No.)
            cout<<"  ";                                       // for decreasing no. sequence ---> (n-Row No.) to n, here k--
        }                                                    // for increasing no. sequence ---> n to (n + Row no.) -1 , here k++
        int k=i;
        for(;j<=n;j++){
            cout<<k--<<" ";
        }
        k=2;
        for(;j<=n+i-1;j++){
            cout<<k++<<" ";
        }
        cout<<endl;
    }

    return 0;
}