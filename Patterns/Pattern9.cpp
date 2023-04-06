#include<iostream>
using namespace std;

int main()
{
    int n,i,j; // 0-1 Right angled triangle

    cout<<"\nEnter no. of rows : ";
    cin>>n;

    cout<<"\nThe required pattern is :\n"<<endl;

    for(i=1;i<=n;i++){                                          //Rows : 1 to n
        for(j=1;j<=i;j++){                                     //Columns : 1 to Row No.
            if((i+j)%2==0){                                   //Elements : if (Row No. + Column No.) = even ---> 1
                cout<<"1 ";                                   // if odd ---> 0
            }
            else {
                cout<<"0 ";
            }
        }
        cout<<endl;
    }

    return 0;
}