#include <iostream>                                             //Using inbuilt MAX & MIN function
#include <bits/stdc++.h>
using namespace std;

int getMin(int arr[], int n) {

    int mini = INT_MAX;

    for(int i=0; i<n; i++) {

        mini = min(mini, arr[i]);
    }

    return mini;
}

int getMax(int arr[], int n) {

    int maxi = INT_MIN;

    for(int i=0; i<n; i++) {

        maxi = max(maxi, arr[i]);
    }

    return maxi;
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

    cout<<"\nMaximum value in the array = "<<getMax(num, size)<<endl;
    cout<<"\nMinimum value in the array = "<<getMin(num, size)<<endl;
    cout<<endl;

    return 0;
}