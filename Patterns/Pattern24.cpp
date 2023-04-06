#include<iostream>
using namespace std;

int main() {

    int n;
    cout<<"\nEnter no. of rows : ";
    cin>>n;

    int i=1;

    while(i<=n){
        int j=1 , space =1;
        while(space<=n-i){                                //For printing space
            cout<<"  ";
            space+=1;
        }
        while(j<=i){                                     //For the 1st triangle
            cout<<j<<" ";
            j+=1;
        }
        j=i-1;                                          //For the 2nd triangle

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