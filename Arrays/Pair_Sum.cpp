#include<iostream>                                                   
#include<vector>                                                    
#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;                                                          
    cout<<"\nEnter the size(length) of the array : ";
    cin>>n;

    int arr[100];
    cout<<"\nEnter the elements of the array : "<<endl;

    for(int i=0; i<n; i++) {                                     //input of array elements
        cin>>arr[i];
    }

    int sum;
    cout<<"\nEnter the value of sum : ";
    cin>>sum;

    cout<<"\nRequired pair(s) is/are : \n";

    for(int i=0;i<n; i++ )
   {
        int temp1, temp2;

           for(int j = i+1; j<n; j++) {
            if(arr[i] + arr[j] == sum)
            {
                
                if(arr[i]<arr[j]) {
            cout<<arr[i]<<" "<<arr[j];
            cout<<endl;
                }
             
            else {
             cout<<arr[j]<<" "<<arr[i]; 
             cout<<endl;
            }
            }
        }
   }
   
   return 0;
}
   
