#include<iostream>
using namespace std;

int main()
{
    int n,i,j; //Butterfly Pattern

    cout<<"\nEnter no. of rows (double of which is to be printed) : ";
    cin>>n;

    cout<<"\nThe required pattern is :\n"<<endl;

    for(i=1;i<=n;i++){                                     // For the upper part
        for(j=1;j<=i;j++){                                // No. of * = 2xRow no.
            cout<<"* ";                                  // No. of spaces = 2xNo. of rows (n) - 2xRow No. (i)
        }                                               // Rows : 1 to n
        int space = 2*n -2*i;
        for(j=1;j<=space;j++){
            cout<<"  ";
        }
        for(j=1;j<=i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }

    for(i=n;i>=1;i--){                                     // For the lower part
        for(j=1;j<=i;j++){                                // Rows : n to 1
            cout<<"* ";
        }
        int space = 2*n -2*i;
        for(j=1;j<=space;j++){
            cout<<"  ";
        }
        for(j=1;j<=i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }

    return 0;
}