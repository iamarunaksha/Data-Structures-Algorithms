#include<iostream>
#include<vector>
using namespace std;

void merge(int arr1[], int n, int arr2[], int m, int arr3[]) {

    int i = 0, j = 0;
    int k = 0;
    while( i<n && j<m) {
        if(arr1[i] < arr2[j]){
            arr3[k++] = arr1[i++];
        }
        else{
            arr3[k++] = arr2[j++];
        }
    }

    //add remaining first array elements      (i value is at the end of if())
    while(i<n) {
        arr3[k++] = arr1[i++];
    }

    //add remaining second array elements    (j value is at the end of else())
    while(j<m) {
        arr2[k++] = arr2[j++];
    }
}

void print(int ans[], int n) {
    
    for(int i=0; i<n; i++) {
        cout<< ans[i] <<" ";
    }
    cout << endl;
}

int main() {

    int size1;
    cout<<"\nEnter the size of the 1st sorted array : ";
    cin>>size1;

    int arr1[100];
    cout<<"\nEnter the elements of the 1st array : "<<endl;

    for(int i=0; i<size1; i++) {
        cin>>arr1[i];
    }

    int size2;
    cout<<"\nEnter the size of the 2nd sorted array : ";
    cin>>size2;

    int arr2[100];
    cout<<"\nEnter the elements of the 2nd array : "<<endl;

    for(int i=0; i<size2; i++) {
        cin>>arr2[i];
    }

    int size3 = size1 + size2;
    int arr3[size3] = {0};
    

    merge(arr1, size1, arr2, size2, arr3);

    cout<<"\nThe sorted merged array : \n";
    print(arr3, size3);

    cout<<endl;

    return 0;
}
