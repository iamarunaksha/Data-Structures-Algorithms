#include<iostream>
using namespace std;

int main()
{
    int rows, cols; //Hollow rectangle

    cout<<"\nEnter no. of rows : ";
    cin>>rows;

    cout<<"\nEnter no. of columns : ";
    cin>>cols;

    cout<<"\nThe required pattern is :\n"<<endl;

    int i,j;

    for(i=1;i<=rows;i++){
        for(j=1;j<=cols;j++){
            if(i==1 || i==rows || j==1 || j==cols){             // or one can use else if as well
                cout<<'*';
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }


    return 0;
}