#include<bits/stdc++.h>                                              // Insertion(at head, tail, any specific pos), Printing a linked list & Deletion
using namespace std;

class Node {

    public:
    
    int data;
    Node* next;

    //constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

    //destructor
    ~Node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
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

bool detectLoop(Node* head) {

    if(head == NULL)
        return false;
    
    map<Node*, bool> visited;

    Node* temp = head;

    while(temp != NULL) {
        
        if(visited[temp])                               // Point of cycle/loop in the linked list
            return true;
        
        visited[temp] = true;
        temp = temp->next;
    }

    return false;
}

bool floydLoopDetect(Node* head) {

    if(head == NULL || head -> next == NULL) 
        return false;
    
    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL) {
        
        fast = fast -> next;

        if(fast != NULL)
            fast = fast -> next;
        
        slow = slow -> next;
        
        if(slow == fast) 
            return true;
    }

    return false;
}

Node* floydLoopDetectNode(Node* head) {

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL) {
        
        fast = fast -> next;

        if(fast != NULL)
            fast = fast -> next;
        
        slow = slow -> next;
        
        if(slow == fast) 
            return slow;
    }

    return NULL;
}

Node* getStartingNode(Node* head) {

    if(head == NULL)
        return NULL;
    
    Node* intersectionNode = floydLoopDetectNode(head);

    if(intersectionNode == NULL)
        return NULL;

    Node* slow = head;

    while(slow != intersectionNode) {

        slow = slow -> next;
        intersectionNode = intersectionNode -> next;
    }

    return slow;
}

void removeLoop(Node* head) {                           // T.C --> O(n)       S.C --> O(1)

    if(head == NULL)
        return;
    
    Node* startOfLoop = getStartingNode(head);

    if(startOfLoop == NULL)
        return;
    
    Node* temp = startOfLoop;

    while(temp -> next != startOfLoop)
        temp = temp -> next;
    
    temp -> next = NULL;                           // At this point after the while loop is executed, temp points to the node that joins to the starting node of the loop. So in this line making next of temp point to NULL.
}

void print(Node* head) {

    if(head == NULL) {                           // Empty linked list, no node to print
        cout << "List is empty"<< endl;
        return ;
    }
    
    Node* temp = head;                          // Temporary pointer pointing to head 

    while(temp != NULL) {
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout<<"NULL"<< endl;
}

void insertAtHead(Node* &head, Node* &tail, int data) {        // Node is sent via reference since we want to make changes in the original linked list not in the copy, so therefore its not passed as a value

    Node* newNode = new Node(data);                     //New node creation
    
    if(head == NULL) {                                 //Empty LinkedList 
        //newNode -> next = NULL;                     //One can't use insertAtTail if this is used. This needs to be used in isolation & data only has to be entered from head then tail = newNode is not needed
        head = newNode;
        tail = newNode;
        return;
    }
    
    newNode -> next = head;                           //Make New node's next pointer point to head node
    head = newNode;                                  //Alter head node with new node                  
}

void insertAtTail(Node* &head, Node* &tail, int data) {
    
    Node* newNode = new Node(data);                      //New node creation   
    
    if(head == NULL) {                                  //Empty LinkedList 
        head = newNode;
        tail = newNode;
        return;
    }

    tail -> next = newNode;                         //Make the existing tail node's next pointer point to newNode
    tail  = newNode;                               //Alter tail node with new node
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

    Node* temp  = head;                   // Temporary pointer pointing to head 
    int cnt = 1;                         // Since at least one node would be present in the linked list now OR simply satrting the counter from 1

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    //inserting at Last Position only. If position value exceeds the last position index then a node can't be inserted
    if(temp -> next == NULL) {
        insertAtTail(head, tail, data);
        return;
    }

    //For insertion of data into the node at a particular position
    Node* nodeToInsert = new Node(data);        
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}

void deleteNode(int position, Node* & head, Node* & tail) { 

    //deleting first or start node
    if(position == 1) {
        Node* temp = head;
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

        prev -> next = curr -> next;

        if(prev -> next == NULL)
            tail = prev;
        
        curr -> next  = NULL;
        delete curr;
    }
}

int main() {

    //Node* node1 = new Node(10);                                 //Node creation
    //cout << node1 -> data << endl;
   //cout << node1 -> next << endl;
    
    Node* head = NULL; 
    Node* tail = NULL;
    //print(head);

    insertAtHead(head, tail, 15);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);

    //print(head);

    insertAtTail(head, tail, 12);

    //print(head);
    
    insertAtTail(head, tail, 16);
    //print(head);

    insertAtPosition(head, tail, 4, 22);
    print(head);

    //tail -> next = head -> next;                            // creating a loop from last node to 2nd node

/*
    cout << "Head -> " << head -> data << endl;
    cout << "Tail -> " << tail -> data << endl;

    deleteNode(6, head, tail);

    print(head); 

    cout << "Head -> " << head -> data << endl;
    cout << "Tail -> " << tail -> data << endl;

    if(isCircular(head))
        cout<<"\nList is circular"<<endl;
    
    else
        cout<<"\nList is not circular"<<endl;
*/

    if(detectLoop(head))
        cout<<"\nLoop is present"<<endl;
    
    else
        cout<<"\nLoop is not present"<<endl;

    if(floydLoopDetect(head))
        cout<<"\nFloyd Loop is present"<<endl;
    
    else
        cout<<"\nFloyd Loop is not present"<<endl;

    return 0;
}