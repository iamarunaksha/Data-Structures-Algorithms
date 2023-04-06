#include<iostream>
using namespace std;

int main() {
    
    int m, n;
    cout<<"\nEnter the no. of rows & columns in the 2D matrix : ";
    cin>> m >> n;
    
    int arr[m][n];
    
    //declaring array elements
    //int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,14,16};
    //int arr[3][4] = {{1,11,111,1111}, {2,22,222,2222}, {3,33,333,3333}};

    cout <<"\nEnter the elements of the 2D matrix : "<<endl;
    //taking input -> row wise input
    for(int row=0; row<m; row++) {
        for(int col=0; col<n; col++) {
            cin >> arr[row][col];
        }
    }
    
    cout <<"\nThe 2D array is : "<<endl;
    //print 
    for(int row=0; row<m; row++) {
        for(int col=0; col<n; col++) {
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }

    return 0;
}