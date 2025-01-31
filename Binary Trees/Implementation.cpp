#include<bits/stdc++.h>
using namespace std;

class node {
public :
    
    int data;
    node* left;
    node* right;

    node(int data) {

        this -> data = data;

        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildTree(node* root) {

    int data;
    cout<<"\nEnter the value : ";
    cin>>data;

    if(data == -1)
        return NULL;

    root = new node(data);

    cout<<"\nValue to be inserted to the left of node "<<data<<endl;
    root -> left = buildTree(root -> left);

    cout<<"\nValue to be inserted to the right of node "<<data<<endl;
    root -> right = buildTree(root -> right);
    
    return root;
}

void levelOrderTraversal(node* root) {

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {

        node* temp = q.front();
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

void reverseLevelOrder(node* root) {

    stack<node*> st;

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {

        node* temp = q.front();
        q.pop();

        if(temp == NULL) {
            
            st.push(NULL);

            if(!q.empty())
                q.push(NULL);
        }

        else {

            st.push(temp);

            if(temp -> right)
                q.push(temp -> right);
            
            if(temp -> left)
                q.push(temp -> left);
        }
    }

    while(!st.empty()) {

        node* temp = st.top();
        st.pop();
        
        if(temp == NULL)
            cout<<endl;
        
        else 
            cout<<temp -> data<<" ";
    }
}

void inorder(node* root) {

    if(root == NULL)
        return;
    
    //L
    inorder(root -> left);

    //N
    cout<<root -> data<<" ";

    //R
    inorder(root -> right);
}

void inorderIterative(node* root) {
    
    stack<node*> s;
    node* curr = root;

    while(curr || !s.empty()) {

        // Reach the left most Node of the curr Node
        while(curr) {
    
            //Insert current tree node on the stack before traversing the node's left subtree
            s.push(curr);
            
            curr = curr -> left;
        }

        // Current must be NULL at this point
        curr = s.top();
        s.pop();

        cout << curr->data << " ";

        //The node and its left subtree is visited. Now, it's right subtree's turn
        curr = curr->right;
    }
}

void preorder(node* root) {

    if(root == NULL)
        return;
    
    //N
    cout<<root -> data<<" ";
    
    //L
    preorder(root -> left);
    
    //R
    preorder(root -> right);
}

void preOrderIterative(node *root) {
    
    if(!root)
        return;

    stack<node*> st;
    st.push(root);

    while(!st.empty()) {

        node* curr = st.top();
        st.pop();

        cout<<curr -> data<<" ";

        if(curr -> right)
            st.push(curr -> right);
        
        if(curr -> left)
            st.push(curr -> left);
    }
}

void postorder(node* root) {

    if(root == NULL)
        return;
    
    //L
    postorder(root -> left);
    
    //R
    postorder(root -> right);
    
    //N
    cout<<root -> data<<" ";
}

void postOrderIterative1(node * root) {     //Using 2 stacks
    
    if(!root)
        return;

    stack<node*> st1, st2;
    st1.push(root);

    while(!st1.empty()) {

        node* curr = st1.top();
        st1.pop();

        st2.push(curr);

        if(curr -> left)
            st1.push(curr -> left);
        
        if(curr -> right)
            st1.push(curr -> right);
    }

    while(!st2.empty()) {

        cout<<st2.top() -> data<<" ";
        st2.pop();
    }
}

void postOrderIterative2(node* root) {      //Using 1 stack

    if(!root)
        return;
    
    stack<node*> st;
    st.push(root);

    vector<int> postorder;

    while(!st.empty()) {
        
        node* curr = st.top();
        st.pop();

        if(curr -> left)
            st.push(curr -> left);
        
        if(curr -> right)
            st.push(curr -> right);

        postorder.push_back(curr -> data);
    }

    reverse(begin(postorder), end(postorder));

    for(auto &it : postorder)
        cout<<it<<" ";
}

void buildFromLevelOrder(node* &root) {

    int data;
    cout<<"\nEnter the value : ";
    cin>>data;

    root = new node(data);
    
    queue<node*> q;
    q.push(root);

    while(!q.empty()) {

        node* temp = q.front();
        q.pop();

        int leftData;
        cout<<"\nEnter the value for the left node of "<<temp -> data<<endl;
        cin>>leftData;

        if(leftData != -1) {

            temp -> left = new node(leftData);

            q.push(temp -> left);
        }

        int rightData;
        cout<<"\nEnter the value for the right node of "<<temp -> data<<endl;
        cin>>rightData;

        if(rightData != -1) {

            temp -> right = new node(rightData);

            q.push(temp -> right);
        }
    }
}

int main() {

    /*
    node* root = NULL;
    root = buildTree(root);

    cout<<"\nPrinting the level order traversal of the B-Tree"<<endl;
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    levelOrderTraversal(root);
    
    cout<<"\nPrinting the reverse level order traversal of the B-Tree"<<endl;
    reverseLevelOrder(root);

    cout<<"\nInorder traversal of the B-Tree"<<endl;
    inorder(root);

    cout<<"\nInorder traversal of the B-Tree (iterative)"<<endl;
    inorderIterative(root);

    cout<<"\nPreorder traversal of the B-Tree"<<endl;
    preorder(root);

    cout<<"\nPostorder traversal of the B-Tree"<<endl;
    postorder(root);
    */

    node* root = NULL;
    buildFromLevelOrder(root);
    levelOrderTraversal(root);

    return 0;
}