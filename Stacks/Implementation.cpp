#include<iostream>
using namespace std;

class Stack {
    //Properties
    public:
        int *arr;
        int top;
        int size;

    //Behaviour
    Stack(int size) {
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element) {
        if((size - top) > 1) {
            top++;
            arr[top] = element;
        }
        else
            cout<<"\nStack OverFlow"<<endl;
    }

    void pop() {
        if(top >= 0) 
            top--;
        
        else
            cout<<"\nStack UnderFlow"<<endl;
    }

    int peek() {
        if(top >= 0)
            return arr[top];
        
        else {
            cout<<"\nStack is Empty"<<endl;
            return -1;
        }
    }

    void getSize() {
        if(top == -1)
            cout<<"\nStack Underflow OR Stack is empty."<<endl;
        
        else
            cout<<"\nSize of stack is : "<<(top+1)<<endl;
    }

    bool isEmpty() {
        if(top == -1) 
            return true;
        
        else
            return false;
    }
};

int main() {

    Stack s1(10);

    s1.push(20);
    s1.push(30);

    s1.getSize();

    return 0;
}