#include<bits/stdc++.h>
using namespace std;

class Heap {                               // Max Heap

public:
	
	vector<int> heapArray;
	int size;

	Heap() {
		size = 0;                           // Initially size is 0, since heap is empty
	}

	void insert(int val) {                 // O-based indexing      || T.C --> O(logn)
		
		heapArray.push_back(val);
        
		size++;

        int index = size - 1;             // Since its 0-based indexing
		
		while(index > 0) {

			int parentIndex = (index-1)/2;              // For 1 based indexing parentIndex = index/2

			if (heapArray[index] > heapArray[parentIndex]) {
				swap(heapArray[index],heapArray[parentIndex]);
				index = parentIndex;
			}

			else
				break;
		}
	}

    int deleteNode() {              // Deletion is always done at root node & lat child is replaced with root & then new root is placed at its correct position

        int ans = heapArray[0];    // T.C --> O(logn)
        
        //Replace root node value with last node value
        heapArray[0] = heapArray[size-1];
        size--;

        //Place root node value at its correct position
        int index = 0;

        while(index < size) {

            int leftChild = 2*index + 1;
            int rightChild = 2*index + 2;

            int largest = index;

            if((leftChild < size) && (heapArray[largest] < heapArray[leftChild])) 
                largest = leftChild;

            if((rightChild < size) && (heapArray[largest] < heapArray[rightChild])) 
                largest = rightChild;
            
            if(largest == index)                    // Root node is at its correct position
                break;
            
            else {
                swap(heapArray[largest], heapArray[index]);
                index = largest;
            }
        }

        return ans;
    }

	~Heap() {			//Destructor

	}
};

int main() {

    Heap h;

    h.insert(10);
    h.insert(15);
    h.insert(20);
    h.insert(30);
    h.insert(40);

    cout<<"\nBefore deletion : "<<endl;

    for(int i=0; i<h.size; i++) 
        cout<<h.heapArray[i]<<" ";

    cout<<endl;

    h.deleteNode();

    cout<<"\nAfter deletion : "<<endl;

    for(int i=0; i<h.size; i++) 
        cout<<h.heapArray[i]<<" ";
    
    // for(int it : h.heapArray) 
    //     cout<<it<<" ";

    return 0;
}