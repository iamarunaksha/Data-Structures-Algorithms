#include<iostream>
using namespace std;

int getSum(int arr[], int n) {

    int sum = 0;
    
    for(int i=0; i<n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {

    int size;
    cout<<"\nEnter the size of the array : ";
    cin>>size;

    int inp_arr[100];
    cout<<"\nEnter the elements of the array : "<<endl;

    for(int i=0; i<size; i++) {
        cin>>inp_arr[i];
    }

    cout<<"\nSum of the elements of the array = "<<getSum(inp_arr, size);
    cout<<endl;

    return 0;
}