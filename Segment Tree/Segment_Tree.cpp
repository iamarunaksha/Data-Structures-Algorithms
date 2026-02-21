#include<bits/stdc++.h>
using namespace std;

class SegmentTree {     //Segment Tree (essentially a Balanced B-Tree) is a data structure that allows us to perform efficient range queries and range/interval updates on an array in logarithmic time. All nodes except leaf nodes have 2 children. The leaf nodes represent the individual elements of the array, while the internal nodes represent the range of values (from index i to j) in the array. The root node represents the entire array (0 to (n - 1)). Height is ceil(log2(n))
    
    int n;                // Size of the original array
    
    vector<int> tree;    // The segment tree array. Total nodes in the tree is approximately 2n. Left child is at (2i + 1) and right child is at (2i + 2). The parent of node i is at (i - 1)/2. The root node is at index 0.
    
    vector<int> lazy;       // The lazy tree array. Total nodes in the tree is same as in segment tree. It stores values that needs to be propagated to these indices in the segment tree, once updateRange hits these indices. It stores values to be propagated for the timebeing or for eternity, if those nodes are never visited during updateRange calls.

public:

    SegmentTree(int n) { // Constructor to initialize the segment tree with size n. The size of the segment tree is 2 * n - 1.
        
        this -> n = n;
        
        int h = (int)(ceil(log2(n))); // Height of the segment tree
        
        int max_size = (4 * n); // Maximum size of the segment tree. If n is not a power of 2, then we need to append some extra/dummy nodes to the segment tree. The maximum size of the segment tree is 2^(h + 1) - 1, which is approximately 4n. (Imp question from interview perspective)
        
        tree.resize(max_size); // Resize the segment tree to the maximum size
        
        lazy.resize(max_size);
    }

    void buildTreeRangeSum(int i, int l, int r, vector<int> &arr) {     // Build the segment tree in O(4n) = O(n) time. The buildTree function is called recursively to build the segment tree. The base case is when l == r, which means we have reached a leaf node. In this case, we set the value of the node to the corresponding element in the array. Otherwise, we calculate the mid-point of the range and recursively call buildTree for the left and right children. Finally, we combine the results of the left and right children to set the value of the current node.
        
        if(l == r) {
            
            tree[i] = arr[l];           //tree[i] = arr[r];
            
            return;
        }

        int mid = (l + r) / 2;
        
        buildTreeRangeSum(((2 * i) + 1), l, mid, arr);
        buildTreeRangeSum(((2 * i) + 2), (mid + 1), r, arr);
        
        tree[i] = tree[(2 * i) + 1] + tree[(2 * i) + 2];
    }

    //T.C --> O(logn)
    void updateTreeRangeSum(int idx, int val, int i, int l, int r) {    // Update the value of the array element at index idx (in arr) to val. The updateTree function is called recursively to update the segment tree.

        if(l == r) {
            
            tree[i] = val; // Update the value of the node to the new value
            
            return;
        }

        int mid = (l + r) / 2;
        
        // If the index is less than or equal to mid, update the left child
        if(idx <= mid) 
            updateTreeRangeSum(idx, val, ((2 * i) + 1), l, mid);
        
        // Update the right child    
        else 
            updateTreeRangeSum(idx, val, ((2 * i) + 2), (mid + 1), r);
        
        tree[i] = tree[(2 * i) + 1] + tree[(2 * i) + 2]; // Update the value of the current node to the sum of its children
    }

    //T.C --> O(logn)
    int queryRangeSum(int start, int end, int i, int l, int r) { // Query the sum of the range [start, end].

        if((l > end) || (r < start)) // If the range is outside the current node's range, return 0
            return 0;

        if((l >= start) && (r <= end)) // If the range is completely inside the current node's range, return the value of the node
            return tree[i];

        int mid = (l + r) / 2;
        
        int left = queryRangeSum(start, end, ((2 * i) + 1), l, mid);             // Query the left child
        int right = queryRangeSum(start, end, ((2 * i) + 2), (mid + 1), r);     // Query the right child

        int ans = left + right; // Combine the results of the left and right children

        return ans; // Return the sum of the range [start, end]
    }

    //T.C --> O(logn)     ||    S.C --> O(4n) {for lazy array}
    void updateRange(int start, int end, int val, int i, int l, int r) {           // Update the value of the array elements from indices start to end to arr[i] += val. The updateTree function is called recursively to update the segment tree.
        
        if(lazy[i] != 0) {
            
            tree[i] += ((r - l + 1) * lazy[i]);
            
            if(l != r) {        //This is not a leaf/single node
                
                lazy[(2 * i) + 1] += lazy[i];   //Left child
                
                lazy[(2 * i) + 2] += lazy[i];  //Right child
            }
            
            lazy[i] = 0;
        }
        
        //Out of Range
        if((r < start) || (l > end) || (l > r))
            return;
        
        //If this segment is in range
        else if((start <= l) && (end >= r)) {
            
            tree[i] += ((r - l + 1) * val);
            
            //Lazy propagation
            if(l != r) {        //This is not a leaf/single node
                
                lazy[(2 * i) + 1] += val;   //Left child
                
                lazy[(2 * i) + 2] += val;  //Right child
            }
            
            return;
        }
        
        //Currently in a segment that is in an overlapping range (start to end)
        int mid = l + (r - l) / 2;
        
        updateRange(start, end, val, ((2 * i) + 1), l, mid);
        updateRange(start, end, val, ((2 * i) + 2), (mid + 1), r);
        
        tree[i] = tree[(2 * i) + 1] + tree[(2 * i) + 2];
    }
};

int main() {
    return 0;
}
