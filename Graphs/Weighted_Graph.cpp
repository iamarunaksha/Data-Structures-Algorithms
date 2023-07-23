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

    //Greedy Algorithm
    void shortestDistanceDijkstras(int src, int n) {        // T.C --> O(E log(V)) {because of set}

        vector<int> distance(n, INT_MAX);

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
};

int main() {

    Graph g;

    //g.addEdge(source node, destination node, weight, directed(1) / undirected(0));
    g.addEdge(6, 3, 2, 0);
    g.addEdge(6, 1, 14, 0);
    g.addEdge(3, 1, 9, 0);
    g.addEdge(3, 2, 10, 0);
    g.addEdge(1, 2, 7, 0);
    g.addEdge(2, 4, 15, 0);
    g.addEdge(4, 3, 11, 0);
    g.addEdge(6, 5, 9, 0);
    g.addEdge(4, 5, 6, 0);
    
    
    g.print();

    //For undirected graph
    /*
    int src = 0;
    int dest = 4;

    g.shortestPathBFS(src, dest);
    */

    /*
    stack<int> topoOrder;
    unordered_map<int, bool> visited;

    g.topologicalSortDFS(0,visited,topoOrder);

    g.shortestDistanceDFS(3, 5, topoOrder);
    */

    g.shortestDistanceDijkstras(6, 7);

    return 0;
}