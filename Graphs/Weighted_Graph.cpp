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

    //MSSP --> Multiple Source Shortest Path
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
    //g.addEdge(0, 1, 5, 0);    //For shortestPathDijkstras
    */

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
