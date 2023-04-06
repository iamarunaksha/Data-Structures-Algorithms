#include<bits/stdc++.h>                                 // a bit complex approach, Babbar
using namespace std;

int partition(vector<int> &arr, int start, int end) {

    int pivot = arr[start];                            //pivot element 
    int count = 0;

    for(int i = start+1; i<=end; i++){                 //i start from start+1 bcoz pivot is at start
    
        if(arr[i]<=pivot) count++;
    
    }
    
    int pivotIndex = start + count;

    swap(arr[pivotIndex],arr[start]);                  //placed pivot element at its right/correct position

    int i = start, j = end;                           //placing smaller elements on the left of pivot & larger ones on the right

    while(i<pivotIndex && j>pivotIndex) {

        while(arr[i] <= pivot) i++;

        while(arr[j] > pivot) j--;

        if(i<pivotIndex && j>pivotIndex) {
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }

    return pivotIndex;
}

void quickSort(vector<int> &arr, int start, int end) {

    if(start>=end) return;                          //base case

    int p_Index = partition(arr, start, end);

    quickSort(arr, start, p_Index-1);
    quickSort(arr, p_Index+1, end);
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