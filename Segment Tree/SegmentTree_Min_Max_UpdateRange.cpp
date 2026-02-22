#include <bits/stdc++.h>
using namespace std;

//Use the same code for LC 3721. Longest Balanced Subarray II
class SegmentTree {

  vector<int> segMin, segMax, lazy;

public:
  SegmentTree(int n) {

    int max_size = (4 * n);

    segMin.assign(max_size, 0);
    segMax.assign(max_size, 0);

    lazy.assign(max_size, 0);
  }

  void propagate(int i, int l, int r) {
    
      if(lazy[i] != 0) {
              
          segMin[i] += lazy[i];
          segMax[i] += lazy[i];
  
          if(l != r) {
              
              lazy[(2 * i) + 1] += lazy[i];
              
              lazy[(2 * i) + 2] += lazy[i];
          }
  
          lazy[i] = 0;
      }
  }

  //Range add val to [start, end] & update the max & min of that range in the respective segMin & segMax arrays
  void updateRangeMaxMin(int start, int end, int val, int i, int l, int r) {
    
      propagate(i, l, r); //Make sure to propagate before hand
  
      //Out of range
      if((l > end) || (r < start)) 
          return;
  
      //[start...end] is fully inside range of current node [l..r]
      if((l >= start) && (r <= end)) {
          
          lazy[i] += val;
          
          propagate(i, l, r);
          
          return;
      }
  
      int mid = l + (r - l) / 2;
      
      updateRangeMaxMin(start, end, val, ((2 * i) + 1), l, mid);
      updateRangeMaxMin(start, end, val, ((2 * i) + 2), (mid + 1), r);
  
      segMin[i] = min(segMin[(2 * i) + 1], segMin[(2 * i) + 2]);
      segMax[i] = max(segMax[(2 * i) + 1], segMax[(2 * i) + 2]);
  }

  int leftMostOccurrence(int i, int l, int r, int val) {            //Gives the left-most occurrence of val provided there's a structure of elements in the array (min & max) like {-1, ..., 0, ..., 1, 0,..., -1} 
      
      propagate(i, l, r);
  
      if((segMin[i] > val) || (segMax[i] < val)) 
          return -1;
  
      if(l == r) 
          return l;
  
      int mid = l + (r - l) / 2;
      
      int leftResult = leftMostOccurrence(((2 * i) + 1), l, mid, val);
      
      if(leftResult != -1)
          return leftResult;
      
      return leftMostOccurrence(((2 * i) + 2), (mid + 1), r, val);
  }
};

int main() {
  return 0;
}
