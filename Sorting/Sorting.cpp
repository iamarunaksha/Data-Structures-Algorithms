#include<bits/stdc++.h>
using namespace std;

void selection_sort(vector<int> &arr,int n) {                          // Worst Case, Best Case & Avg. Case Time Complexity = O(n^2), Space Complexity = O(1)

    for(int i=0; i<=n-2; i++) {                                       // i < n-1;
        int mini = i;
        for(int j=i; j<=n-1; j++) {                                  // j = i+1; j < n;
            if(arr[j]<arr[mini]) {
                mini = j;
            }
        }
        
        //swap(arr[mini],arr[i]);                               // when swap is used, temp variable is not needed.

        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
}

void bubble_sort(vector<int> &arr, int n) {                       // Worst Case, Avg. Case  Time Complexity = O(n^2), Best Case Time Complexity = O(n), Space Complexity = O(1)

    for(int i=n-1; i>=1; i--) {
        
        int did_swap = 0;

        for(int j=0; j<=i-1; j++) {                             // j <= i - 1; or else j+1 would be out of range & give run time error for i = n-1.
            if(arr[j]>arr[j+1]) {
                swap(arr[j],arr[j+1]);
                did_swap = 1;
            }
        }

        if(did_swap == 0)
            break;
    }
}

void bubbleSort(vector<int>& arr, int n)                        // 2nd Approach
{   
    for(int round = 1; round<n; round++) {                     // for(int round = 0; round < (n-1); round++) {
        //for round 1 to n-1
        bool swapped = false;
        
        for(int j = 0; j<n-round; j++) {                       //for(int j = 0; j < (n-round-1); j++) {
            
            //process element till n-i th index
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
            
        }
        
        if(swapped == false) {
            //already sorted
            break;
        }

    }
}

void insertion_sort(vector<int> &arr, int n) {                 // Worst Case, Avg. Case  Time Complexity = O(n^2), Best Case Time Complexity = O(n), Space Complexity = O(1)

    for(int i=1; i<n; i++) {
        
        int j = i;

        while(j>0 && arr[j-1] > arr[j]) {
            
            int temp = arr[j-1];

            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;

            /*swap(arr[j-1],arr[j]);                           // for easy implementation but, in insertion sort there's shifting happening not swapping
            j--; */
        }
    }
}

void insertionSort(vector<int> &arr, int n){                   //2nd Approach, not a better version
    
    for(int i = 1; i<n; i++) {                                // i = 1; bcoz we are considering i = 0 to be sorted at first
        int temp = arr[i];
        int j = i-1;
        for(; j>=0; j--) {
            
            if(arr[j] > temp) {
                //shift
                arr[j+1] = arr[j];
            }
            else { // ruk jao
                break;
            }
            
        }
        //copy temp value
        arr[j+1] = temp;  
    } 
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

    //selection_sort(arr,n);
    //bubble_sort(arr,n);
    insertion_sort(arr,n);

    cout<<"\nSorted array using Insertion Sort : ";
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;

    return 0;
}
