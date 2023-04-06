#include<iostream>                                                   //valid only for a sorted array
#include<vector>                                                    //optimised sol.
using namespace std;

int main() {

    int n;                                                          //1st array
    cout<<"\nEnter the size(length) of the 1st array : ";
    cin>>n;

    int arr1[100];
    cout<<"\nEnter the elements of the 1st array : "<<endl;

    for(int i=0; i<n; i++) {                                     //input of array elements
        cin>>arr1[i];
    }

    int m;                                                          //2nd array
    cout<<"\nEnter the size(length) of the 2nd array : ";
    cin>>m;

    int arr2[100];
    cout<<"\nEnter the elements of the 2nd array : "<<endl;

    for(int i=0; i<m; i++) {                                     //input of array elements
        cin>>arr2[i];
    }
    
    cout<<"\nIntersection of the 2 array is : ";

    int i = 0, j = 0;
    
    while(i<n && j<m) {                                          //2-pointer approach
    
    if(arr1[i]==arr2[j])
    {
        cout<<arr1[i]<<" ";
        i++;
        j++;
    }
    else if (arr1[i] < arr2[j]) {
          i++;
    }
    else
    {
        j++;
    }
    
    }

    return 0;
}