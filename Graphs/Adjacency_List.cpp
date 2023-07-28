#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph {
public:

    unordered_map<T, list<T>> adjList;                  // S.C --> O(V +E) {avg. case}  ||  O(V^2) {worst case}

    void addEdge(T u, T v, bool direction) {

        adjList[u].push_back(v);

        //Undirected Graph
        if(!direction) 
            adjList[v].push_back(u);
    }

    void print() {

        for(auto node : adjList) {

            cout<<node.first<<" -> ";

            /*
            for(auto neighbor : node.second) 
                cout<<neighbor<<", ";
            */
            
            /*
            auto it = node.second.begin();
            
            if (it != node.second.end()) {
                cout<<*it;
                it++;
            }
            
            for(; it != node.second.end(); it++) 
                cout<<", " <<*it;
            */

            auto it = node.second.begin();

            cout<<*it++;

            for(; it != node.second.end(); it++)
                cout<<", " <<*it;
            
            cout<<endl;
        }
    }

    void bfs(T src) {                                   // T.C --> O(V +E)    ||  S.C --> O(V)

        queue<T> q;

        unordered_map<T, bool> visited;                 // Map uses additional space O(V)

        q.push(src);
        visited[src] = true;

        int printedElements = 0;
        int totalElements = adjList.size();

        while(!q.empty()) {

            T frontNode = q.front();
            q.pop();
            
            cout<<frontNode;
            
            for(auto neighbour : adjList[frontNode]) {

                if(!visited[neighbour]) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }

            if (++printedElements < totalElements) 
                cout << ", ";
        
        }
    }

    //Especially for disconnected graphs
    void bfs_LevelOrder(T src, unordered_map<T, bool> &visited) {

        queue<T> q;

        q.push(src);
        visited[src] = true;

        int printedElements = 0;
        int totalElements = adjList.size();

        while(!q.empty()) {

            T frontNode = q.front();
            q.pop();
            
            cout<<frontNode;
            
            for(auto neighbour : adjList[frontNode]) {

                if(!visited[neighbour]) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }

            if (++printedElements <= totalElements) 
                cout << ", ";
        
        }
    }

    void dfs(T src, unordered_map<T, bool> &visited, bool &first) {         // T.C --> O(V + E)     ||   S.C --> O(V)

        if (!first) 
            cout<<", ";
        
        else 
            first = false;
    
        cout<<src;
        visited[src] = true;

        for(auto neighbour : adjList[src]) {

            if(!visited[neighbour]) 
                dfs(neighbour, visited, first);
        }
    }

    bool checkCycleBFS(T src, unordered_map<T, bool> &visited) {

        queue<T> q;
        unordered_map<T, T> parent;

        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while(!q.empty()) {

            T frontNode = q.front();
            q.pop();

            for(auto neighbour : adjList[frontNode]) {

                if(!visited[neighbour]) {
                    
                    q.push(neighbour);
                    visited[neighbour] = true;
                    parent[neighbour] = frontNode;
                }

                //Neighbour is already visited
                else {

                    //Cycle is present
                    if(neighbour != parent[frontNode]) 
                        return true;
                    
                }
            }
        }

        return false;
    }

    bool checkCycleDFS(T src, unordered_map<T, bool> &visited, T parent) {

        visited[src] = true;

        for(auto neighbour : adjList[src]) {

            if(!visited[neighbour]) {

                bool forwardAns = checkCycleDFS(neighbour, visited, src);

                if(forwardAns) 
                    return true;
            }

            //Very Imp to use else if instead of only if
            else if(visited[neighbour] && neighbour != parent)
                return true;
        }

        return false;
    }

    bool cycleCheckDirectedGraphDFS(T src, unordered_map<T, bool> &visited, unordered_map<T, bool> &recursionStack) {

        visited[src] = true;
        recursionStack[src] = true;

        for(auto neighbour : adjList[src]) {

            if(!visited[neighbour]) {

                bool forwardAns = cycleCheckDirectedGraphDFS(neighbour, visited, recursionStack);

                if(forwardAns) 
                    return true;
            }

            //Very Imp to use else if instead of only if
            else if(visited[neighbour] && recursionStack[neighbour])
                return true;
        }

        //Backtrack
        recursionStack[src] = false;

        return false;
    }

    //Topological sort is valid only for DAG. Directed Acyclic Graph
    void topologicalSortDFS(T src, unordered_map<T, bool> &visited, stack<T> &ans) {

        visited[src] = true;

        for(auto neighbour : adjList[src]) {

            if(!visited[neighbour]) 
                topologicalSortDFS(neighbour, visited, ans);
        }

        //While returning store the element in the stack
        ans.push(src);
    }

    //Kahn's algorithm    ||  Also used for cycle detection using BFS. If ans.size() == n then no cycle, if ans.size() != n then cycle is present (In Directed Graph)
    void topologicalSortBFS(int n, vector<int> &ans) {

        queue<T> q;
        unordered_map<T, T> indegree;

        //Indegree Calculation
        for(auto it : adjList) {

            //T src = it.first;

            for(auto neighbour : it.second) 
                indegree[neighbour]++;
        }

        for(int i=0; i<n; i++) {

            if(indegree[i] == 0)
                q.push(i);
        }

        //Use BFS Logic
        while(!q.empty()) {

            T fNode = q.front();
            q.pop();

            ans.push_back(fNode);

            for(auto neighbour : adjList[fNode]) {

                indegree[neighbour]--;

                if(indegree[neighbour] == 0)
                    q.push(neighbour);
            }
        }
    }

    //If we only want to print the count, then no need of cout statements
    void dfsSCC(T src, unordered_map<T, bool> &visited, unordered_map<int, list<int>> &newAdjList, bool first) {

        if (!first) 
            cout<<", ";
        
        else 
            first = false;
    
        cout<<src;
        
        visited[src] = true;

        for(auto neighbour : newAdjList[src]) {

            if(!visited[neighbour])
                dfsSCC(neighbour, visited, newAdjList, first);
        }
    }

    string getSuffix(int n) {
        
        if (n == 1 || n == 21 || n == 31) 
            return "st";
        
        if (n == 2 || n == 22) 
            return "nd";
        
        if (n == 3 || n == 23) 
            return "rd";

        return "th";
    }

    //Kosaraju's Algorithm
    int countStronglyConnectedComponents(int n) {           // T.C --> O(V+E)   ||  S.C --> O(V+E)
        
        stack<int> st;          //S.C --> O(V)

        unordered_map<int, bool> visitedTopo;   // S.C --> O(V)

        //Step 1 : Find the topological ordering of the given graph    ||  T.C --> O(V + E)
        for(int i=0; i<n; i++) {

            if(!visitedTopo[i])
                topologicalSortDFS(i, visitedTopo, st);
        }

        unordered_map<int, list<int>> newAdjList;       // S.C --> O(V+E)

        //Step 2 : Reverse all the edges in the graph & store it in a new adjList    ||  T.C --> O(V + E)
        for(auto it : adjList) {

            for(auto neighbour : it.second) {

                int u = it.first;
                int v = neighbour;

                //Reverse the adjList in the newAdjList
                newAdjList[v].push_back(u);
            }
        }

        //Step 3 : Traverse the newAdjList using DFS      ||  T.C --> O(V + E)

        int count = 0;
        
        unordered_map<int, bool> visitedDFS;
        
        while(!st.empty()) {

            int node = st.top();
            st.pop();

            if(!visitedDFS[node]) {

                cout<<"\nPrinting "<<count+1<<getSuffix(count+1)<<" SCC : ";
                
                dfsSCC(node,visitedDFS, newAdjList, true);
                
                cout<<endl;
                
                count++;
            }
        }

        return count;
    }

    //Tarjan's Algorithm
    void findBridges(int src, int parent, int &timer, vector<int> &insertionTime, vector<int> &lowerTime, unordered_map<int, bool> &visited) {

        visited[src] = true;
        insertionTime[src] = timer;
        lowerTime[src] = timer;

        timer++;

        for(auto neighbour : adjList[src]) {

            if(neighbour == parent)
                continue;
            
            if(!visited[neighbour]) {

                //DFS call
                findBridges(neighbour, src, timer, insertionTime, lowerTime, visited);

                //Low Update
                lowerTime[src] = min(lowerTime[src], lowerTime[neighbour]);             // Might not be the shortest route always but if updated it indicates there exists an alternate path to that node apart from the 1st parent from which its visited

                //Check for bridge
                if(insertionTime[src] < lowerTime[neighbour])
                    cout<<neighbour<<"--"<<src<<" is a bridge"<<endl;
            }

            //Node visited & not a parent --> only update lowerTime array for src
            else
                lowerTime[src] = min(lowerTime[src], insertionTime[neighbour]);
        }
    }
};

void printBFS(Graph<int> g, int n) {
    
    unordered_map<int, bool> visited;  
    
    cout<<"\nPrinting BFS Traversal :"<<endl;
    
    //For disconnected graphs follow this approach (works for connected graphs as well)
    for(int i=0; i<n; i++) {

        if(!visited[i])
            g.bfs_LevelOrder(i, visited);
    }
    
    //g.bfs(0);
}

void printDFS(Graph<int> g, int n) {

    unordered_map<int, bool> visited; 
    bool first = true;

    cout<<"\nPrinting DFS Traversal :"<<endl;

    for(int i=0; i<n; i++) {

        if(!visited[i])
            g.dfs(i, visited, first);
    }
}

void undirectedCycleCheckBFS(Graph<int> g, int n) {

    // For Cycle check using BFS
    unordered_map<int, bool> visited; 
    bool ans = false;

    for(int i=0; i<n; i++) {

        if(!visited[i]) {

            ans = g.checkCycleBFS(i, visited);

            if(ans)
                break;
        }
    }

    if(ans)
        cout<<"\nCycle is present"<<endl;
    
    else
        cout<<"\nCycle is not present"<<endl;
}

void undirectedCycleCheckDFS(Graph<int> g, int n) {

    // For Cycle check using DFS
    unordered_map<int, bool> visitedCycle; 
    bool ans = false;

    for(int i=0; i<n; i++) {

        if(!visitedCycle[i]) {

            ans = g.checkCycleDFS(i, visitedCycle, -1);

            if(ans)
                break;
        }
    }

    if(ans)
        cout<<"\nCycle is present"<<endl;
    
    else
        cout<<"\nCycle is not present"<<endl;
}

void directedCycleCheckDFS(Graph<int> g, int n) {

    unordered_map<int, bool> visited;
    unordered_map<int, bool> recursionStack;  
    bool ans = false;

    for(int i=0; i<n; i++) {

        if(!visited[i]) {

            ans = g.cycleCheckDirectedGraphDFS(i, visited, recursionStack);

            if(ans)
                break;
        }
    }

    if(ans)
        cout<<"\nCycle is present"<<endl;
    
    else
        cout<<"\nCycle is not present"<<endl;
}

void topologicalSortusingDFS(Graph<int> g, int n) {

    //Topological Sort
    unordered_map<int, bool> visitedTopologicalSort;
    stack<int> ans;

    for(int i=0; i<n; i++) {

        if(!visitedTopologicalSort[i]) 
            g.topologicalSortDFS(i, visitedTopologicalSort, ans);
    }

    cout<<"\nPrinting Topological Sort using DFS :"<<endl;

    while(!ans.empty()) {

        int topElement = ans.top();
        ans.pop();

        if (!ans.empty()) 
            cout<<topElement<<", ";
        
        else 
            cout<<topElement;
    }

    cout<<endl;
}

void topologicalSortusingBFS(Graph<int> g, int n) {

    vector<int> ans;

    //For both connected/disconnected graph
    g.topologicalSortBFS(n, ans);

    if(ans.size() == n)
        cout<<"\nValid TopologicalSort"<<endl;
    
    else
        cout<<"\nCycle is present in the directed graph"<<endl;
    
    cout<<"\nPrinting Topological Sort using BFS :"<<endl;

    bool first = true;
    
    for (auto it : ans) {
        
        if (!first) 
            cout << ", ";

        cout << it;
        first = false;
    }
    
    cout<<endl;
}

void printFindBridges(Graph<int> g, int n) {
    
    vector<int> tin(n);
    
    vector<int> low(n);

    unordered_map<int, bool> visited;

    int timer = 0;

    cout<<"\nPrinting the bridge(s) (if found) :"<<endl;
    
    g.findBridges(0, -1, timer, tin, low, visited);
}

int main() {

    Graph<int> g;

    int n = 7;          // No. of nodes

    /*
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(2, 0, 0);
    g.addEdge(1, 6, 0);
    g.addEdge(3, 1, 0);
    g.addEdge(1, 4, 0);
    g.addEdge(3, 5, 0);
    g.addEdge(4, 5, 0);
    */

    /*
    g.addEdge(0, 1, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(2, 1, 0);
    g.addEdge(0, 3, 0);
    g.addEdge(3, 4, 0);
    */
    
    printFindBridges(g, n);
    
    /*
    //SCC
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,0,1);
    g.addEdge(2,4,1);
    g.addEdge(4,5,1);
    g.addEdge(5,6,1);
    g.addEdge(6,4,1);
    g.addEdge(6,7,1);

    int ans = g.countStronglyConnectedComponents(8);

    cout<<"\nNo. of strongly connected components in the graph is : "<<ans<<endl;
    */
    
    //DAG
    /*
    g.addEdge(2, 4, 1);
    g.addEdge(2, 5, 1);
    g.addEdge(4, 6, 1);
    g.addEdge(5, 3, 1);
    g.addEdge(3, 7, 1);
    g.addEdge(6, 7, 1);
    g.addEdge(7, 0, 1);
    g.addEdge(7, 1, 1);
    */
    

    //Cyclic Directed Graph
    /*
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 1, 1);
    */

    /*
    topologicalSortusingDFS(g, n);

    topologicalSortusingBFS(g,n);
    */

    return 0;
}