#include<iostream>                                              //Important
using namespace std;

int main()
{
    int n; // No. right-angled triangle

    cout<<"\nEnter no. of rows : ";
    cin>>n;

    cout<<"\nThe required pattern is :\n"<<endl;

    int row=1;

    while(row<=n){
        
        int col=row;
        while(col < 2*row){
            cout<<col<<" ";
            col+=1;
        }

        cout<<endl;
        row+=1;
    }

    return 0;
}