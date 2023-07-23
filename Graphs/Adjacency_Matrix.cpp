#include<bits/stdc++.h>
using namespace std;

int main() {

    int nodes;
    cout<<"\nEnter the number of nodes : ";
    cin>>nodes;

    vector<vector<int>> adj(nodes, vector<int>(nodes, 0));              // S.C --> O(v^2)

    int edges;
    cout<<"\nEnter the number of edges : ";
    cin>>edges;

    cout<<"\nEnter the node no.s between which edges are present : "<<endl;

    for(int i=0; i<edges; i++) {

        int u,v;
        cin>>u>>v;

        //Marking 1 in adj matrix
        adj[u][v] = 1;
    }

    cout<<"\nThe adjacency matrix : "<<endl;

    for(int i=0; i<nodes; i++) {

        for(int j=0; j<nodes; j++) 
            cout<<adj[i][j]<<" ";
        
        cout<<endl;
    }

    return 0;
}