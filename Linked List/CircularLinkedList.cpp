#include<bits/stdc++.h>
using namespace std;

class Node {

    public :

    int data;
    Node* next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

    ~Node() {
        
        int value = this -> data;

        if(this -> next != NULL) {
            delete next;
            this -> next = NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
    }
};

bool isCircular(Node* tail){                          // T.C --> O(n)       S.C --> O(1)
    
    if(tail == NULL)                                // OR if(tail == NULL || tail -> next == tail)
        return true;                               //return NULL; depending on question. Whether an empty list is considered to be circular or not.
    
    /*
    if(tail -> next == NULL)
        return false;
    */
    
    Node* temp = tail;

    do {
        temp = temp -> next;
    }while(temp != tail && temp != NULL);

    if(temp == NULL)
        return false;
    
    return true;
}

bool detectLoop(Node* tail) {

    if(tail == NULL)
        return false;
    
    map<Node*, bool> visited;

    Node* temp = tail;

    while(temp != NULL) {
        
        if(visited[temp])                               // Point of cycle/loop in the linked list
            return true;
        
        visited[temp] = true;
        temp = temp->next;
    }

    return false;
}

int getLength(Node* tail) {

    int len = 0;

    Node* temp = tail;

    do {
        len++;
        temp = temp -> next;
    } while (temp != tail);
    
    return len; 
}

void insertNode(Node* &tail, int element, int data) {
    
    Node* newNode = new Node(data);
    
    //Empty List
    if (tail == NULL) { 
        tail = newNode;
        newNode -> next = newNode;
    }

    else {
        
        Node* curr = tail;

        /*
        while(curr -> data != element)
            curr = curr -> next;
        */

        do {
            if(curr -> data == element)
                break;

            else
                curr = curr -> next;
        } while(curr != tail); 

        if(curr -> data != element) {
            cout<<"\nElement is not present in the list therefore node cannot be inserted"<<endl;
            return;
        }
        
        //After the do while loop, if element is found then current points to that node containing the element
        newNode -> next = curr -> next;
        curr -> next = newNode;
    }
}

void print(Node* tail) {

    if(tail == NULL) {                           // Empty linked list, no node to print
        cout << "List is empty"<< endl;
        return ;
    }
    
    Node* temp = tail;                          // Temporary pointer pointing to tail 

    do {
        cout << temp -> data << " ";
        temp = temp -> next;
    } while(temp != tail);

    cout<< endl;
}

void deleteNode(Node * &tail, int value) {

    if(tail == NULL) {
        cout<<"\nList is empty! Nothing to delete"<<endl;
        return;
    }

    else {

        Node* prev = tail;                              // Initially prev is pointing at tail
        Node* curr = prev -> next;                     // & curr at the 1st node of the list(if LL is thought as a linear one)
        
        /*
        while(curr -> data!= value) {                // This while loop works only when value is present in the Linked List
            prev = curr;
            curr = curr -> next;
        }
        */

        do {                                       // Much more generalized code, works even when value to be deleted is not present in the Linked List
            if(curr -> data == value)
                break;

            else {
                prev = curr;
                curr = curr -> next;
            }
        } while(prev != tail); 

        if(curr -> data != value) {
            cout<<"\nElement is not present in the list therefore node cannot be deleted"<<endl;
            return;
        }

        prev -> next = curr -> next;

        if(curr == prev)                                 // If Linked List contains only 1 node
            tail = NULL;

        else if (tail == curr)                         // OR (tail -> next == curr -> next), since in this code 3 is the tail only. So if we want to delete the tail node then tail needs to be re updated 
            tail = prev;                              // OR tail = curr -> next;

        curr -> next = NULL;
        delete curr;
    }
}

int main() {

    Node* tail = NULL;

    insertNode(tail, 5, 3);
    print(tail);

/*
    insertNode(tail, 3, 9);
    print(tail);

    insertNode(tail, 9, 7);
    print(tail);

    insertNode(tail, 7, 5);
    print(tail);
*/

/*
    if(isCircular(tail))
        cout<<"\nList is circular"<<endl;
    
    else
        cout<<"\nList is not circular"<<endl;

*/

    if(detectLoop(tail))
        cout<<"\nLoop is present"<<endl;
    
    else
        cout<<"\nLoop is not present"<<endl;
    

    //cout<<tail -> data<<endl;

/*
    deleteNode(tail, 9);
    print(tail);
*/

    return 0;
}