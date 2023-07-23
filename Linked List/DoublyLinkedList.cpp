#include<iostream>
using namespace std;

class Node {

    public:

    Node* previous;
    int data;
    Node* next;

    Node(int data) {
    
        this -> previous = NULL;
        this -> data = data;
        this -> next = NULL;
    }

    //destructor
    ~Node() {                                           // Good practice to include a destructor in the class to delete any dynamically allocated memory in the heap
        int value = this -> data;
        //memory free
        if(this->next != NULL) {                      // Checks if next of the node to be deleted points to any other node other than NULL, if so then it deletes the next node
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
    }
};

bool isCircular(Node* head){
    
    if(head == NULL || head -> next == head)
            return true;
        
        if(head -> next == NULL)
            return false;
        
        Node* temp = head;

        do {
            temp = temp -> next;
        }while(temp != head && temp != NULL);

        if(temp == NULL)
            return false;
        
        else
            return true;
}

void print(Node* head) {

    if(head == NULL) {                           // Empty linked list, no node to print
        cout << "List is empty"<< endl;
        return ;
    }
    
    Node* temp = head;

    while (temp != NULL) {
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    
    cout<<"NULL"<<endl; 
}

int getLength(Node* head) {

    int len = 0;

    Node* temp = head;

    while (temp != NULL) {
        len++;
        temp = temp -> next;
    }
    
    return len; 
}

void insertAtHead(Node* &head, Node* &tail, int data) { 

    Node* newNode = new Node(data);

    if(head == NULL) {                                  //Empty LinkedList 
        head = newNode;
        tail = newNode;
        return;
    }

    newNode -> next = head;
    head -> previous = newNode;
    head = newNode;
}

void insertAtTail(Node* &head, Node* &tail, int data) {

    Node* newNode = new Node(data);

    if(head == NULL) {                                  //Empty LinkedList 
        head = newNode;
        tail = newNode;
        return;
    }

    tail -> next = newNode;
    newNode -> previous = tail;
    tail = newNode;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int data) {

     //When the LinkedList is empty
    if(head == NULL) {                          
        Node* newNode = new Node(data);
        newNode -> next = NULL;
        head = newNode;
        return;
    }

    //insert at Start
    if(position == 1) {                      //Linked list have 0 based indexing but for ease of undersatnding 1 --> starting
        insertAtHead(head, tail, data);
        return;
    }

    //inserting at Last Position or at a position that exceeeds length of the linked list
    int len = getLength(head);

    if(position >= len) {
        insertAtTail(head, tail, data);
        return;
    }

    Node* temp  = head;                   // Temporary pointer pointing to head 
    int cnt = 1;                         // Since at least one node would be present in the linked list now OR simply satrting the counter from 1

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    /*
    //inserting at Last Position
    if(temp -> next == NULL) {
        insertAtTail(head, tail, data);
        return;
    }
    */

    //For insertion of data into the node at a particular position
    Node* nodeToInsert = new Node(data);        
    nodeToInsert -> next = temp -> next;
    temp -> next -> previous = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> previous = temp;
}

void deleteNode(Node* & head, Node* & tail, int position) { 

    //deleting first or start node
    if(position == 1) {
        Node* temp = head;
        temp -> next -> previous = NULL;
        head = head -> next;
        //memory free start node
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        Node* curr = head;                              // Initially current is at head
        Node* prev = NULL;                             // Previous node has to point at NULL if current node is head

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        curr -> previous = NULL;
        prev -> next = curr -> next;

        if(prev -> next == NULL)
            tail = prev;
        
        curr -> next  = NULL;
        delete curr;
    }
}

int main() {

    //Node* node1 = new Node(10);
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 15);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 45);
    insertAtTail(head, tail, 25);
    print(head);

    insertAtPosition(head, tail, 2, 80);
    print(head);

    insertAtPosition(head, tail, 9, 100);
    print(head);

    deleteNode(head, tail, 3);
    print(head);

    if(isCircular(head))
        cout<<"\nList is circular"<<endl;
    
    else
        cout<<"\nList is not circular"<<endl;

    return 0;
}