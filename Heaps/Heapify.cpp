#include<bits/stdc++.h>                                         // MAX Heap
using namespace std;

void heapify(vector<int> &arr, int n, int i) {                        // Using Recursion, for D.E Shaw.     ||   T.C --> O(logn)

    int index = i;              // 1-based indexing                        
    int leftChild = 2*i;
    int rightChild = 2*i + 1;
    int largest = index;

    if(leftChild <= n && arr[largest] < arr[leftChild])
        largest = leftChild;
    
    if(rightChild <= n && arr[largest] < arr[rightChild])
        largest = rightChild;
    
    if(index != largest) {
        swap(arr[largest], arr[index]);
        index = largest;
        heapify(arr, n, index);
    }
}

void buildHeap(vector<int> &arr, int n) {               // T.C --> O(n)

    for(int i = n/2; i>0; i--)
        heapify(arr, n, i);
}

void heapSort(vector<int> &arr, int n) {            // T.C --> O(nlogn)

    int index = n;

    while(n != 1) {

        swap(arr[1], arr[index]);
        n--;
        index--;

        //Heapify
        heapify(arr, n, 1);
    }

    /*
    No need for index as well

    while(n != 1) {

        swap(arr[1], arr[n--]);

        heapify(arr, n, 1);             //Heapify
    }
    */
}

int main() {

    vector<int> arr = {-1, 12, 56, 43, 6, 78, 87, 5, 44, 3, 23, 32};
    int n = arr.size() - 1;

    buildHeap(arr, n);

    cout<<"\nPrinting the heap elements :"<<endl;

    for(int i=0; i<=n; i++)
        cout<<arr[i]<<" ";
    
    cout<<endl;

    heapSort(arr, n);

    cout<<"\nPrinting the heap elements after heapsort :"<<endl;

    for(int i=0; i<=n; i++)
        cout<<arr[i]<<" ";

    return 0;
}