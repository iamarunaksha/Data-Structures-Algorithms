#include<iostream>                                          //Difficult
using namespace std;                        

int main()
{
    int n,i,j; 
    cout<<"\nEnter no. of rows : ";
    cin>>n;
    

    cout<<"\nThe required pattern is :\n"<<endl;

    for(int i=0; i<2*n-1; i++) {                            // Min. Distance Pattern in numbers
        for(int j=0; j<2*n-1; j++) {

            int top = i;
            int left = j;
            int right = 2*(n-1) - j;
            int bottom = 2*(n-1) - i;

            cout<< n - min(min(top,bottom), min(left,right));
        }
        cout<<endl;
    }
    
    
    return 0;
}