#include<iostream>
using namespace std;

int main()
{
    int rows, cols; //Solid Rectangle Pattern

    cout<<"\nEnter no. of rows : ";
    cin>>rows;

    cout<<"\nEnter no. of columns : ";
    cin>>cols;

    cout<<"\nThe required pattern is :\n"<<endl;

    int i,j;

    for(i=1;i<=rows;i++) {
        for(j=1;j<=cols;j++) {
            cout<<"*";
        }
        cout<<endl;
    }
    
    return 0;
}