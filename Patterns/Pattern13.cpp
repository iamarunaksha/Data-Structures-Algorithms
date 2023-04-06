#include<iostream>
using namespace std;

int main()
{
    int n,i,j; //Star Pattern

    cout<<"\nEnter no. of rows (double of which is to be printed) : ";
    cin>>n;

    cout<<"\nThe required pattern is :\n"<<endl;

    for(i=1;i<=n;i++){                                      // For the upper part
        for(j=1;j<=n-i;j++){                               //Rows : 1 to n
            cout<<"  ";                                    //Columns : Space ---> 1 to (n-Row No.)
        }                                                // for * ---> 1 to [(2*Row No.) - 1]
        for(j=1;j<=2*i-1;j++){
            cout<<" *";
        }
        cout<<endl;
    }

    for(i=n;i>=1;i--){                                    // For the lower part
        for(j=1;j<=n-i;j++){                             //Rows : n to 1
            cout<<"  ";
        }
        for(j=1;j<=2*i-1;j++){
            cout<<" *";
        }
        cout<<endl;
    }

    return 0;
}