#include <iostream>                                             //Finding max & min elements of an array
#include <bits/stdc++.h>
using namespace std;

int getMin(int arr[], int n) {

    int mini = INT_MAX;

    for(int i=0; i<n; i++) {
        if(arr[i] < mini){
            mini = arr[i];
        }
    }

    return mini;
}

int getMax(int arr[], int n) {

    int maxi = INT_MIN;

    for(int i=0; i<n; i++) {
        if(arr[i] > maxi){
            maxi = arr[i];
        }
    }

    return maxi;
}

int main() {

    int size;
    cout<<"\nEnter the size(length) of the array : ";
    cin>>size;

    int num[100];
    cout<<"\nEnter the elements of the array : "<<endl;

    for(int i=0; i<size; i++) {
        cin>>num[i];
    }

    cout<<"\nMaximum value in the array = "<<getMax(num, size)<<endl;
    cout<<"\nMinimum value in the array = "<<getMin(num, size)<<endl;
    cout<<endl;

    return 0;
}