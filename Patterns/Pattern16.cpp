#include<iostream>                                              //Important
using namespace std;

int main()
{
    int n; // No. right-angled triangle

    cout<<"\nEnter no. of rows : ";
    cin>>n;

    cout<<"\nThe required pattern is :\n"<<endl;

    int row=1;
    int temp=1;
    
    while(row<=n){

        int col=1;
        while (col<=row){
            cout<<temp<<" ";
            temp+=1;
            col+=1;
        }
        cout<<endl;
        row+=1;        
    }

    cout<<endl;

    return 0;
}