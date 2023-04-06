#include<iostream>                                              //Important
using namespace std;

int main()
{
    int n,i,j; // Zig-zag Pattern

    cout<<"\nEnter no. of * in zig-zag : ";
    cin>>n;

    cout<<"\nThe required pattern is :\n"<<endl;

    for(i=1;i<=3;i++){
        for(j=1;j<=n;j++){
            if(((i+j)%4==0) || (i==2 && j%4==0)){
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }

    return 0;
}