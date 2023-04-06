#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {

    int size;
    cout<<"\nEnter the size(length) of the array : ";
    cin>>size;

    int num[100];
    cout<<"\nEnter the elements of the array : "<<endl;

    for(int i=0; i<size; i++) {                                     //input of array elements
        cin>>num[i];
    }

    sort(num, num+size);

    cout<<"\nThe sorted array is : ";
    
    for(int i=0; i<size; i++) {
        cout << num[i] << " ";
    }
    cout <<"\n"<<endl;

    return 0;
}