#include<iostream>                                  //Important & difficult
using namespace std;

int main() {

    int n;
    cout<<"\nEnter no. of rows : ";
    cin>>n;

    int i=1;

    while(i<=n){
        int j=1;
        while(j<=n-i+1){
            cout<<j<<" ";
            j+=1;
        }

        j=1;
        while(j<=(i-1)*2){
            cout<<"* ";
            j+=1;
        }

        j=n-i+1;
        while(j>=1){
            cout<<j<<" ";
            j-=1;
        }
        cout<<endl;
        i+=1;
    }

    cout<<endl;

    return 0;
}