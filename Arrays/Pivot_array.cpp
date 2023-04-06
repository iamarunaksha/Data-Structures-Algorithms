#include<iostream>
using namespace std;

int getPivot(int arr[], int n) {

    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s<e) {

        if(arr[mid] >= arr[0])
        {
            s = mid+1;
        }
        else{
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;                                                     //one can also return 'e'
}

int main() {

    int size;
    cout<<"\nEnter the size(length) of the array : ";
    cin>>size;

    int arr[100];
    cout<<"\nEnter the elements of the sorted array : "<<endl;

    for(int i=0; i<size; i++) {                                     //input of array elements
        cin>>arr[i];
    }

    cout << "\nPivot is : " << getPivot(arr, size) <<"th index" << endl;

    return 0;
}