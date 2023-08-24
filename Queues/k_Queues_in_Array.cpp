#include<iostream>
using namespace std;

class kQueues {

    int n;      // Size of array
    int k;     // No of queues in the array

    int *arr;

    int* front;
    int* rear;

    int freeSpot;

    //Initaially it represents the index of next free spot available in the array, when filled it indicates the index of the next element of the same queue
    int* next;

public:

    kQueues(int n, int k) {

        this -> n = n;
        
        this -> k = k;

        arr = new int[n];
        
        front = new int[k];
        rear = new int[k];

        for(int i=0; i<k; i++) 
            front[i] = rear[i] = -1;

        next = new int[n];
        next[n-1] = -1;

        for(int i = 0; i < (n-1); i++)
            next[i] = i + 1;

        freeSpot = 0;
    }

    void enqueue(int data, int ithQueue) {

        //Overflow check
        if(freeSpot == -1) {
            cout<<"\nQueue Overflow"<<endl;
            return;
        }

        //Find first free index
        int index = freeSpot;

        //Update freespot
        freeSpot = next[index];

        //Check whether it's the 1st element of the queue
        if(front[ithQueue - 1] == -1)
            front[ithQueue - 1] = index;
        
        //Link new element to the previous element of the same queue
        else
            next[rear[ithQueue - 1]] = index;
        
        //Update next
        next[index] = -1;

        //Update rear
        rear[ithQueue - 1] = index;

        //Push the element
        arr[index] = data;
    }

    int pop(int ithQueue) {

        //Underflow
        if(front[ithQueue - 1] == -1) {
            cout<<"\nQueue underflow"<<endl;
            return -1;
        }

        //Find the index to pop
        int index = front[ithQueue - 1];

        //Popped element
        int poppedElement = arr[index];
        
        //Remove the element from the arr
        arr[index] = -1;

        //Update front of the queue
        front[ithQueue - 1] = next[index];

        //Update the free slots
        next[index] = freeSpot;
        freeSpot = index;

        return poppedElement;
    }

    bool isFull() {

        //Overflow check
        if(freeSpot == -1) {
            cout<<"\nQueue Overflow, that is queue is full"<<endl;
            return true;
        }

        else {
            cout<<"\nQueue is not full"<<endl;
            return false;
        }
    }

    bool isEmpty(int ithQueue) {

        //Underflow
        if(front[ithQueue - 1] == -1) {
            cout<<"\nQueue underflow, that is queue is empty"<<endl;
            return true;
        }

        else {
            cout<<"\nQueue is not empty"<<endl;
            return false;
        }
    }
};

int main() {

    kQueues q(10, 3);

    q.enqueue(10, 1);
    q.enqueue(15, 1);
    q.enqueue(20, 2);
    q.enqueue(25, 1);

    cout<<q.pop(1)<<endl;
    cout<<q.pop(2)<<endl;
    cout<<q.pop(1)<<endl;
    cout<<q.pop(1)<<endl;
    cout<<q.pop(1)<<endl;

    return 0;
}