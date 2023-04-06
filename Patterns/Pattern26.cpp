#include<iostream>
using namespace std;

int main()
{
    int n,i,j; 
    cout<<"\nEnter no. of rows : ";
    cin>>n;
    

    cout<<"\nThe required pattern is :\n"<<endl;

    for(i=0; i<n; i++) {
        for(char ch='A'+(n-i-1); ch<'A'+n; ch++) {                                      // ch< 'A'+ n = 'A' + (n-i-1) + (i+1)
            cout<<ch<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}