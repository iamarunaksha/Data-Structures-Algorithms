#include<bits/stdc++.h>
using namespace std;

class SegmentTree {     //Segment Tree (essentially a Balanced B-Tree) is a data structure that allows us to perform efficient range queries and range/interval updates on an array in logarithmic time. All nodes except leaf nodes have 2 children. The leaf nodes represent the individual elements of the array, while the internal nodes represent the range of values (from index i to j) in the array. The root node represents the entire array (0 to (n - 1)). Height is ceil(log2(n))
    
    int n;                // Size of the original array

    vector<int> arr;
    
    vector<int> maxTree, minTree; 

public:

    SegmentTree(vector<int> &arr) { // Constructor to initialize the segment tree with size n. The size of the segment tree is 2 * n - 1.
        
        n = arr.size();

        this -> arr = arr;
        
        int h = (int)(ceil(log2(n))); // Height of the segment tree
        
        int max_size = (4 * n); // Maximum size of the segment tree. If n is not a power of 2, then we need to append some extra/dummy nodes to the segment tree. The maximum size of the segment tree is 2^(h + 1) - 1, which is approximately 4n. (Imp question from interview perspective)
        
        maxTree.resize(max_size); // Resize the segment tree to the maximum size
        minTree.resize(max_size); // Resize the segment tree to the maximum size

        buildTreeRangeMinMaxIdx(0, 0, (n - 1));
    }

    void buildTreeRangeMinMaxIdx(int i, int l, int r) {     // Build the segment tree in O(4n) = O(n) time. The buildTree function is called recursively to build the segment tree. The base case is when l == r, which means we have reached a leaf node. In this case, we set the value of the node to the corresponding element in the array. Otherwise, we calculate the mid-point of the range and recursively call buildTree for the left and right children. Finally, we combine the results of the left and right children to set the value of the current node.
        
        if(l == r) {
            
            maxTree[i] = l;           //tree[i] = r;
            minTree[i] = r;
            
            return;
        }

        int mid = (l + r) / 2;
        
        buildTreeRangeMinMaxIdx(((2 * i) + 1), l, mid);
        buildTreeRangeMinMaxIdx(((2 * i) + 2), (mid + 1), r);

        int leftMaxIdx = maxTree[(2 * i) + 1];
        int rightMaxIdx = maxTree[(2 * i) + 2];
        
        maxTree[i] = (arr[leftMaxIdx] >= arr[rightMaxIdx]) ? leftMaxIdx : rightMaxIdx;

        int leftMinIdx = minTree[(2 * i) + 1];
        int rightMinIdx = minTree[(2 * i) + 2];

        minTree[i] = (arr[leftMinIdx] <= arr[rightMinIdx]) ? leftMinIdx : rightMinIdx;
    }

    int queryRangeMax(int start, int end, int i, int l, int r) {     // Query the max element index of the range [start, end].

        if((l > end) || (r < start))   // If the range is outside the current node's range, return 0
            return -1;           //Returning invalid val/index

        if((l >= start) && (r <= end)) // If the range is completely inside the current node's range, return the value of the node
            return maxTree[i];

        int mid = (l + r) / 2;
        
        int leftMaxIdx = queryRangeMax(start, end, ((2 * i) + 1), l, mid);             // Query the left child
        int rightMaxIdx = queryRangeMax(start, end, ((2 * i) + 2), (mid + 1), r);           // Query the right child

        if((leftMaxIdx == -1))
          return rightMaxIdx;
        
        if((rightMaxIdx == -1) || (arr[leftMaxIdx] >= arr[rightMaxIdx]))
          return leftMaxIdx;

        return rightMaxIdx;
    }
};

int main() {

} 
