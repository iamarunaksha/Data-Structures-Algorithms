#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int firstOccur(int arr[],int n,int key)
{
    int left = 0;
    int right = n-1;
    int mid = left + (right-left)/2;
    int ans = -1;                        //if key is not present then return -1 (default value)

    while(left <= right)
    {
        if(arr[mid] == key){
        
            ans = mid;
            right = mid - 1;             //to check whether the current index is the 1st or 1st is present on the left side
        }
        else if(key < arr[mid]){
            
            right = mid - 1;
        } 
        else{
           
            left = mid + 1;
        }
         mid = left + (right-left)/2;
    }
    return ans;  
}

int lastOccur(int arr[],int n,int key)
{
    int left = 0;
    int right = n - 1;
    int mid = left + (right-left)/2;
    int ans = -1;

    while(left <= right)
    {
        if(arr[mid] == key){
            
            ans = mid;
            left = mid + 1;                          //to check the actual last occurrence of the key 
        }
        else if(key < arr[mid]){
            right = mid - 1;
        } 
        else{
            left = mid + 1;
        }
         mid = left + (right-left)/2;
    }
    return ans;   
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

    int key;
    cout<<"\nEnter the element whose occurence needs to be checked : ";
    cin>>key;

    int a = firstOccur(arr,size,key);
    cout<<"\nFirst occurenece of "<<key<<" is : "<<firstOccur(arr,size,key);
   
    int b = lastOccur(arr,7,key);
    cout<<"\n\nLast occurenece of "<<key<<" is :"<<lastOccur(arr,size,key);

    if(a != -1 && b != -1) {
    
    int totalOccur = (b - a) + 1;
    cout<<"\n\nTotal no.of occurenece of "<<key<<" is : "<<totalOccur;

    }
    else {
        int totalOccur = 0;
    cout<<"\n\nTotal no.of occurenece of "<<key<<" is : "<<totalOccur;
    }

    cout<<"\n"<<endl;

    return 0;
}