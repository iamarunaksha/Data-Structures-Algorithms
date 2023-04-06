#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high) {

    int pivot = arr[low];                                               // actual sorting of the array is done here in this function
    
    int i = low;
    int j = high;

    while(i<j) {

        while(arr[i]<=pivot && i <= high-1) {                         // for ascending order
            i++;
        }

        while(arr[j]>pivot && j >= low+1) {
            j--;
        }

        /*
        while(arr[i]>=pivot && i <= high-1) i++;                       // for descending order

        while(arr[j]<pivot && j >= low+1) j--;
        */

        if(i<j) swap(arr[i],arr[j]);

    }
    
    int p_Index = j;

    swap(arr[low],arr[p_Index]);

    return p_Index;
}

void quickSort(vector<int> &arr, int low, int high) {               // Time Complexity (Best Case, Avg. Case) ---> O(nlogn), Worst Case ---> O(n^2) ;  Space Complexity ---> O(n)

    if(low<high) {

        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex-1);                      //left side of the array
        quickSort(arr, pivotIndex+1, high);                    //right side of the array
    }

    //else case would be the base case, no need to specify it explicitly
}

int main() {

    int n;
    cout<<"\nEnter the size of the array : ";
    cin>>n;

    vector<int> arr(n);

    cout<<"\nEnter the elements of the array : ";

    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    quickSort(arr,0,n-1);

    cout<<"\nSorted array using Quick Sort : ";
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;
    
    return 0;
}