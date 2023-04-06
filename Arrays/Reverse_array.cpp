#include<iostream>
using namespace std;

void reverse(int arr[], int n) {

    int start = 0;
    int end = n-1;

    while(start<=end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void printArray(int arr[], int n) {
    
    cout<<"\nRequired array is : "<<endl;
    
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    int size;
    cout<<"\nEnter the size(length) of the array : ";
    cin>>size;

    int num[100];
    cout<<"\nEnter the elements of the array : "<<endl;

    for(int i=0; i<size; i++) {                                     //input of array elements
        cin>>num[i];
    }

    reverse(num, size);
    
    printArray(num, size);

    cout<<endl;

    return 0;
}