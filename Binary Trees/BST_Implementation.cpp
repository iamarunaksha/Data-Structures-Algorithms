#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    
    int data;
    Node* right;
    Node* left;

    Node(int data) {

        this -> data = data;
        
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* insertIntoBST(Node* root, int data) {     // T.C --> O(logn)

    if(root == NULL) {

        root = new Node(data);

        return root;
    }

    //Insert into right part of root
    if(data > root -> data) 
        root -> right = insertIntoBST(root -> right, data);
    
    else
        root -> left = insertIntoBST(root -> left, data);
    
    return root;
}

void levelOrderTraversal(Node* root) {

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {

        Node* temp = q.front();
        q.pop();

        if(temp == NULL) {
            
            cout<<endl;

            if(!q.empty())
                q.push(NULL);
        }

        else {
            
            cout<<temp -> data<<" ";
            
            if(temp -> left)
                q.push(temp -> left);
            
            if(temp -> right)
                q.push(temp -> right);
        }
    }
}

void takeInput(Node* &root) {

    int data;
    cin>>data;

    while(data != -1) {

        root = insertIntoBST(root, data);

        cin>>data;
    }
}

void findPredecessorSuccessor(Node* root, Node*& pre, Node*& suc, int key) {
    
    // Base Case
    if(root == NULL)  
        return;

    // If key is present at root
    if(root -> data == key) {
        
        // the maximum value in left subtree is predecessor
        if(root -> left) {
            
            Node* temp = root -> left;
            
            while(temp -> right)
                temp = temp -> right;
            
            pre = temp;
        }

        // the minimum value in right subtree is successor
        if(root -> right) {
            
            Node* temp = root -> right ;
            
            while (temp -> left)
                temp = temp -> left;
            
            suc = temp;
        }
        return;
    }

    // If key is smaller than root's key, go to left subtree
    if(root -> data > key) {
        
        //suc = root;
        
        findPredecessorSuccessor(root -> left, pre, suc, key);
    }
    
    // go to right subtree
    else {
        
        //pre = root;
        
        findPredecessorSuccessor(root -> right, pre, suc, key);
    }
}

int main() {

    Node* root = NULL;

    cout<<"\nEnter data to create BST :"<<endl;
    takeInput(root);

    cout<<"\nPrinting the level order traversal of the BST :"<<endl;
    levelOrderTraversal(root);

    Node* pre = NULL;
    Node* suc = NULL;
    
    int key;
    cout<<"\nEnter the key value : ";
    cin>>key;

    findPredecessorSuccessor(root, pre, suc, key);

    if(pre)
        cout<<"\nInorder predecessor of "<<key<<" is : "<<pre -> data<<endl;
    
    else
        cout<<"\nNo predecessor of "<<key<<endl;
    
    if(suc)
        cout<<"\nInorder successor of "<<key<<" is : "<<suc -> data<<endl;
    
    else
        cout<<"\nNo successor of "<<key<<endl;

    return 0;
}