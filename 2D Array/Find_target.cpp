#include<iostream>
using namespace std;

//to find a target element
template <int m, int n>
bool isPresent(int array[m][n], int target, int row, int col) {

for(int row=0; row<m; row++) {
        for(int col=0; col<n; col++) {
            
            if( arr[row][col] == target) {
                return 1;
            }
            
        }
    }

    return 0;
}

int main() {

    int m, n;
    cout<<"\nEnter the no. of rows & columns in the 2D matrix : ";
    cin>> m >> n;

    int arr[m][n];

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

    cout <<"\nEnter the element to search : ";
    int target;
    cin>>target;

    if(isPresent(arr, target, m, n)) {
        cout <<"\nTarget Element "<<target<<" found"<<endl;
    }
    else{
        cout <<"\nTarget Element "<<target<<" not found"<<endl;
    }

    return 0;
}