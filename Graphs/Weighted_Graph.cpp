#include<bits/stdc++.h>
using namespace std;

class Graph {
public:

    unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int u, int v, int weight, bool direction) {

        adjList[u].push_back({v, weight});

        //Undirected Graph                  0 -> undirected  || 1 -> directed
        if(!direction) 
            adjList[v].push_back({u, weight});
    }

    void print() {

        cout<<"\nPrinting the adjacency list for the graph along with their weights :"<<endl;

        for(auto node : adjList) {

            cout<<node.first<<" -> ";
            
            /*
            for(auto neighbour : node.second) 
                cout<<"{"<<neighbour.first<<", "<<neighbour.second<<"}, ";
            
            cout<<endl;
            */

            bool isFirst = true;
            
            for (auto neighbor : node.second) {
                
                if (!isFirst) 
                    cout<<", ";
                
                cout << "{" << neighbor.first << ", " << neighbor.second << "}";
                
                isFirst = false;
            }
            
            cout<<endl;
        }
    }

    //Topological sort is valid only for DAG. Directed Acyclic Graph
    void topologicalSortDFS(int src, unordered_map<int, bool> &visited, stack<int> &ans) {

        visited[src] = true;

        for(auto neighbour : adjList[src]) {

            if(!visited[neighbour.first]) 
                topologicalSortDFS(neighbour.first, visited, ans);
        }

        //While returning store the element in the stack
        ans.push(src);
    }

    //For equi-weighted graphs
    void shortestPathBFS(int src, int dest) {

        queue<int> q;

        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;

        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while(!q.empty()) {

            int fNode = q.front();
            q.pop();

            for(auto neighbour : adjList[fNode]) {

                if(!visited[neighbour.first]) {

                    q.push(neighbour.first);
                    visited[neighbour.first] = true;
                    parent[neighbour.first] = fNode;
                }
            }
        }

        vector<int> ans;

        int node = dest;

        while(node != -1) {

            ans.push_back(node);

            node = parent[node];
        }

        reverse(ans.begin(), ans.end());

        cout<<"\nPrinting the shortest path using BFS :"<<endl;

        bool first = true;

        for (auto it : ans) {
            
            if (!first) 
                cout<<"-> ";

            cout<<it;
            first = false;
        }
        
        cout<<endl;
    }

    void shortestDistanceDFS(int dest, int n, stack<int> &topoOrder) {

        vector<int> distance(n, INT_MAX);               // For finding shortest path we need a parent DS

        int src = topoOrder.top();
        topoOrder.pop();

        distance[src] = 0;

        for(auto neighbour : adjList[0]) {

            if(distance[0] + neighbour.second < distance[neighbour.first]) 
                distance[neighbour.first] = distance[0] + neighbour.second;
        }

        while(!topoOrder.empty()) {

            int topElement = topoOrder.top();
            topoOrder.pop();

            if(distance[topElement] != INT_MAX) {

                for(auto neighbour : adjList[topElement]) {

                    if(distance[topElement] + neighbour.second < distance[neighbour.first]) 
                        distance[neighbour.first] = distance[topElement] + neighbour.second;
                }
            }
        }

        cout<<"\nPrinting shortest distance using DFS :\n"<<endl;

        for (int i=0; i<distance.size(); i++)
            cout<<i<<" -> "<<distance[i]<<endl; 
    }

    void shortestPathDijkstras(int src, int dest, int n) { 

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, src});

        vector<int> dist(n, INT_MAX), parent(n);
        dist[src] = 0;

        for(int i=0; i<n; i++)
            parent[i] = i;
        
        while(!minHeap.empty()) {

            auto top = minHeap.top();
            minHeap.pop();

            int node = top.second;
            int d = top.first;

            for(auto &nbr : adjList[node]) {

                int adjNode = nbr.first;
                int wt = nbr.second;

                int newDist = wt + d;

                if(newDist < dist[adjNode]) {

                    dist[adjNode] = newDist;

                    minHeap.push({dist[adjNode], adjNode});

                    parent[adjNode] = node;
                }
            }
        }

        if(dist[dest] == INT_MAX) {

            cout<<"There is no path between "<<src<<" and "<<dest<<endl;

            return;
        }

        vector<int> path;

        int node = dest;

        while(parent[node] != node) {

            path.push_back(node);

            node = parent[node];
        }

        path.push_back(node);       //Pushing the src node, instead of node src can be pushed as well

        reverse(begin(path), end(path));

        cout<<"Shortest path between "<<src<<" and "<<dest<<" is as follows : "<<endl;

        bool first = true;

        for(auto &it : path) {

            if(!first)
                cout<<" -> ";
            
            cout<<it;

            first = false;
        }   
    }

    //Greedy Algorithm   ||  SSSP --> Single Source Shortest Path
    void shortestDistanceDijkstras(int src, int n) {        // T.C --> O(V^2 + E log(V)) {because of set}    || S.C --> O(2V) {1 V for array & 1 V for set}

        vector<int> distance(n, INT_MAX);             //  O(V^2) in T.C term comes from the removal of the minimum distance node in each iteration, and the algorithm processes each edge at most once.

        set<pair<int, int>> st;                     // We can use either a set or a min Heap

        distance[src] = 0;
        st.insert(make_pair(0, src));

        while(!st.empty()) {

            //Fetch the smallest or 1st element from the set
            auto top = *(st.begin());

            int nodeDistance = top.first;
            int node = top.second;

            //Pop from set
            st.erase(st.begin());

            for(auto neighbour : adjList[node]) {

                if(nodeDistance + neighbour.second < distance[neighbour.first]) {

                    //Finding entry in the set
                    auto res = st.find(make_pair(distance[neighbour.first], neighbour.first));

                    if(res != st.end()) 
                        st.erase(res);
                    
                    distance[neighbour.first] = nodeDistance + neighbour.second;

                    st.insert(make_pair(distance[neighbour.first], neighbour.first));
                }
            }
        }

        cout<<"\nPrinting Shortest Distance using Dijkstra's Algo :"<<endl;

        bool first = true;

        for (int i=0; i<distance.size(); i++) {
            
            if(!first)
                cout<<", ";
            
            cout<<distance[i];
            
            first = false;
        }
        
        cout<<endl;
    }

    //SSSP --> Single Source Shortest Path
    void negativeEdgesBellmanFord(int src, int n) {         // T.C --> O(V x E)   ||  S.C --> O(V) for distance array

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        //Perform n-1 Relaxation iterations
        for(int i = 0; i < (n-1); i++) {

            for(auto t : adjList) {

                for(auto neighbour : t.second) {

                    int u = t.first;
                    int v = neighbour.first;
                    int wt = neighbour.second;

                    //Actual relaxation step
                    if(dist[u] != INT_MAX && dist[u] + wt < dist[v])
                        dist[v] = dist[u] + wt;
                }
            }
        }

        //To check for negative edge cycle

        bool isNegativeCycle = false;

        for(auto t : adjList) {

            for(auto neighbour : t.second) {

                int u = t.first;
                int v = neighbour.first;
                int wt = neighbour.second;

                //Actual relaxation step
                if(dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                    
                    isNegativeCycle = true;
                    
                    break;
                }
            }
        }

        if(isNegativeCycle)
            cout<<"\nNegative cycle detected"<<endl;
        
        else
            cout<<"\nNegative cycle is not detected"<<endl;

        cout<<"\nPrinting results of Bellman Ford algorithm :"<<endl;

        bool first = true;

        for (int i=0; i<dist.size(); i++) {
            
            if(!first)
                cout<<", ";
            
            cout<<dist[i];
            
            first = false;
        }
        
        cout<<endl;
    }

    //MSSP --> Multiple Source Shortest Path, not the most optimal because of the higher T.C
    void floydWarshall(int n) {                                     // T.C --> O(V^3)   ||  S.C --> O(V^2)

        vector<vector<int>> dist(n, vector<int>(n, 1e9));         // INT_MAX is not used bcoz in (dist[src][helper] + dist[helper][dest]) step there would be INT overflow adding something to INT_MAX would give -ive no & that would be takean as min.

        //Mark Diagonal elements of dist matrix as 0
        for(int i=0; i<n; i++)
            dist[i][i] = 0;
        
        //Insert distance into dist matrix as per the graph
        for(auto t : adjList) {

            for(auto neighbour : t.second) {

                int u = t.first;
                int v = neighbour.first;
                int wt = neighbour.second;

                dist[u][v] = wt;
            }
        }

        for(int helper = 0; helper < n; helper++) {
            for(int src = 0; src < n; src++) {
                for(int dest = 0; dest < n; dest++)
                    dist[src][dest] = min(dist[src][dest], (dist[src][helper] + dist[helper][dest]));
            }
        }

        cout<<"\nPrinting the result of Floyd Warshall algorithm :"<<endl;       
        
        for (int i=0; i<dist.size(); i++) {
            
            bool first = true;

            for(int j=0; j<dist[i].size(); j++) {

                if(!first)
                    cout<<", ";
                
                cout<<dist[i][j]; 

                first = false;                
            }

            cout<<endl;                       
        }
        
        cout<<endl;
    }

    int getMinKeyNode(vector<int> &key, vector<bool> &mst) {
        
        int mini = INT_MAX;     //Key value
        
        int index = -1;      //Node
        
        for(int i=0; i<key.size(); i++) {
            
            if((key[i] < mini) && !mst[i]) {
                
                mini = key[i];
                
                index = i;
            }
        }
        
        return index;
	}

    //Works only on connected undirected graphs. Greedy Algorithm
    void primsAlgorithmBruteForce(int n) {       //T.C --> O(n^2)   ||  S.C --> O(4n)

        vector<int> key(n, INT_MAX), parent(n, -1);     //Key serves as tracking the minimum edge wt. to reach that node(i)
        key[0] = 0;     //Starting with node 0 in the MST, any node can be chosen if mot 0

        vector<bool> mst(n, false);     //Indicates whether the node 'i' has been included in the MST or not

        for(int i=1; i<n; i++) {        //Since there will be n-1 edges in the MST, so we loop for n-1 times, O(n^2)

            //Step 1 : Find index or node with min value that is not added to mst
            int u = getMinKeyNode(key, mst);        //O(n)

            /*
            if(u == -1)     //Redundant part, can be removed
                break;
            */

            //Step 2 : Add the node into the MST list
            mst[u] = true;  //Node 'u' has been included in the MST

            //Step 3 : Process all adjacent nodes of u
            for(auto &edge : adjList[u]) {      //O(n)
                
                int v = edge.first;
                int w = edge.second;
                
                if(!mst[v] && (w < key[v])) {
                    
                    key[v] = w;
                    
                    parent[v] = u;
                }
            }
        }

        vector<vector<int>> edges;

        for(int i=1; i<n; i++)      //O(n)
            edges.push_back({parent[i], i});
        
        int mstSum = 0;

        for(int u=0; u<n; u++)      //O(n)
            mstSum += key[u];
        
        cout<<"Edges in the MST are : "<<endl;

        for(auto &edge : edges) 
            cout<<edge[0]<<" -> "<<edge[1]<<", edge wt : "<<key[edge[1]]<<endl;
        
        cout<<endl<<"MST sum : "<<mstSum<<endl;
    }

    void primsAlgorithmOptimal1(int n) {       //T.C --> O(n (logn + E))   ||  S.C --> O(4n)

        vector<int> key(n, INT_MAX), parent(n, -1);     //Key serves as tracking the minimum edge wt. to reach that node(i)
        key[0] = 0;     //Starting with node 0 in the MST, any node can be chosen if mot 0

        vector<bool> mst(n, false);     //Indicates whether the node 'i' has been included in the MST or not

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, 0});       //{key, node}    
        
        while(!minHeap.empty()) {        //Since there will be n-1 edges in the MST, so we loop for n-1 times, O(n (logn + E))

            auto top = minHeap.top();   //O(1)
            minHeap.pop();  //O(logn)

            //Step 1 : Find index or node with min value that is not added to mst
            int u = top.second;        //O(logn)

            //Step 2 : Add the node into the MST list
            mst[u] = true;  //Node 'u' has been included in the MST

            //Step 3 : Process all adjacent nodes of u
            for(auto &edge : adjList[u]) {      //O(E)
                
                int v = edge.first;
                int w = edge.second;
                
                if(!mst[v] && (w < key[v])) {
                    
                    key[v] = w;
                    
                    parent[v] = u;

                    minHeap.push({w, v});
                }
            }
        }

        vector<vector<int>> edges;

        for(int i=1; i<n; i++)      //O(n)
            edges.push_back({parent[i], i});
        
        int mstSum = 0;

        for(int u=0; u<n; u++)      //O(n)
            mstSum += key[u];
        
        cout<<"Edges in the MST are : "<<endl;

        for(auto &edge : edges)     //O(E)
            cout<<edge[0]<<" -> "<<edge[1]<<", edge wt : "<<key[edge[1]]<<endl;
        
        cout<<endl<<"MST sum : "<<mstSum<<endl;
    }

    void primsAlgorithmOptimal2(int n) {        //T.C --> O(E) + O(logE + O(ElogE)) ≈ O(ElogE)  ||  S.C --> O(n + E)

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;    //S.C --> O(E)
        minHeap.push({0, 0, -1});     //{wt, node, parent}
        
        vector<int> mst(n, false);    //S.C --> O(n)
        
        int mstSum = 0;
        
        vector<vector<int>> edges;
        
        while(!minHeap.empty()) {
            
            auto top = minHeap.top();
            minHeap.pop();
            
            int node = top[1], parent = top[2];
            
            int wt = top[0];
            
            if(mst[node])
                continue;
            
            mst[node] = true;       //Adding the node in the MST
            
            mstSum += wt;
            
            if(parent != -1)
                edges.push_back({parent, node, wt});
            
            for(auto &it : adjList[node]) {
                
                int adjNode = it.first;
                int adjWt = it.second;
                
                if(!mst[adjNode])
                    minHeap.push({adjWt, adjNode, node});
            }
        }
        
        cout<<"Edges in the MST are : "<<endl;

        for(auto &edge : edges)     //O(E)
            cout<<edge[0]<<" -> "<<edge[1]<<", edge wt : "<<edge[2]<<endl;
        
        cout<<endl<<"MST sum : "<<mstSum<<endl;
    }
};

int main() {

    Graph g;

    //g.addEdge(source node, destination node, weight, directed(1) / undirected(0));
    /*
    g.addEdge(6, 3, 2, 0);
    g.addEdge(6, 1, 14, 0);
    g.addEdge(3, 1, 9, 0);
    g.addEdge(3, 2, 10, 0);
    g.addEdge(1, 2, 7, 0);
    g.addEdge(2, 4, 15, 0);
    g.addEdge(4, 3, 11, 0);
    g.addEdge(6, 5, 9, 0);
    g.addEdge(4, 5, 6, 0);
    
    /* For primsAlgorithm
    g.addEdge(0, 1, 2, 0);
    g.addEdge(0, 2, 1, 0);
    g.addEdge(0, 3, 3, 0);
    */
    
    //g.addEdge(0, 1, 5, 0);    //For shortestPathDijkstras
    */
    
    //g.primsAlgorithmOptimal2(7);

    //Bellman Ford
    /*
    g.addEdge(0,1,-1,1);
    g.addEdge(0,2,4,1);
    g.addEdge(1,2,3,1);
    g.addEdge(1,3,2,1);
    g.addEdge(1,4,2,1);
    g.addEdge(3,1,1,1);
    g.addEdge(3,2,5,1);
    g.addEdge(4,3,-3,1);
    */

    //Floyd Warshall 
    g.addEdge(0,1,3,1);
    g.addEdge(0,3,5,1);
    g.addEdge(1,0,2,1);
    g.addEdge(1,3,4,1);
    g.addEdge(2,1,1,1);
    g.addEdge(3,2,2,1);


    g.print();

    //For undirected graph
    /*
    int src = 0;
    int dest = 4;

    g.shortestPathBFS(src, dest);

    g.shortestPathDijkstras(src, dest, 7);
    */

    /*
    stack<int> topoOrder;
    unordered_map<int, bool> visited;

    g.topologicalSortDFS(0,visited,topoOrder);

    g.shortestDistanceDFS(3, 5, topoOrder);
    */

    // g.shortestDistanceDijkstras(1, 4);

    // g.negativeEdgesBellmanFord(1, 4);

    g.floydWarshall(4);

    return 0;
}
