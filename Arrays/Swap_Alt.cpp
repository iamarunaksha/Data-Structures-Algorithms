#include<iostream>
using namespace std;

void SwapAlt(int arr[], int size) {

    for(int i=0; i<size; i+=2) {
        if(i+1 < size) {
            swap(arr[i], arr[i+1]);
        }
    }
}

void printArray(int arr[], int size) {

    cout<<"\nRequired array is : "<<endl;
    
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
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

    SwapAlt(num, size);

    printArray(num, size);

    cout<<endl;

    return 0;
}