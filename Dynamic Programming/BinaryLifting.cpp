#include <bits/stdc++.h>
using namespace std;

class BinaryLifting {

    int n;
    int LOG;
    
    vector<vector<int>> ancestor;

public:
    BinaryLifting(int n, vector<int> &parent) {

        this -> n = n;

        LOG = 32 - __builtin_clz(n);   // ceil(log2(n)) + 1

        ancestor.assign(n, vector<int>(LOG, -1));

        // 2^0-th ancestor = 1st/immediate ancestor of a node
        for(int i = 0; i < n; i++)
            ancestor[i][0] = parent[i];

        // Build Binary Lifting Table
        for(int j = 1; j < LOG; j++) {

            for(int node = 0; node < n; node++) {

                int prev = ancestor[node][j - 1];

                if(prev != -1)
                    ancestor[node][j] = ancestor[prev][j - 1];
            }
        }
    }

    int kthAncestor(int node, int k) {

        for(int j = 0; j < LOG; j++) {

            if(k & (1 << j)) {     //Bit pos where 1 is present in k (binary)

                node = ancestor[node][j];

                if(node == -1)
                    return -1;
            }
        }

        return node;
    }
};

int main() {

    int n = 7;

    vector<int> parent = {-1, 0, 0, 1, 1, 2, 2};    //parent array => Immediate ancestor/parent of a node

    BinaryLifting bl(n, parent);

    cout<<bl.kthAncestor(6, 1)<<endl;   // 2
    cout<<bl.kthAncestor(6, 2)<<endl;   // 0
    cout<<bl.kthAncestor(6, 3)<<endl;   // -1
}
