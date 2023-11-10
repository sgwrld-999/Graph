//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/*
The intitution behind the code is that there is dependcy of one node on another node.How?
Let's say we have a graph with and their is a directed edge from u to v and we can reach 
u to v in 2 differenet ways 
Path 1 :  u -> x -> v[1,10]
Path 2 :  u -> y -> x -> v[1,5,1]
To reach v from u we can either go through x or y->x.
To reach v we must reach x first and then we can reach v. And to reach x we can either go through u or y.
So, we can say that there is a dependcy of x on u and y. 
And since in the question the given graph is a DAG(Directed Acyclic Graph) so we can say that
there is no cycle in the graph and we can reach any node from any node.
So, we can say that there is a dependcy of x on u and y and there is no dependcy of u and y on x. 
We can think of Topo logical sort as a way to sort the nodes in such a way that the dependcy of a node
By compuing the distance of each node from the source node we can get the shortest distance from the source node to each node.
That was the intution behind the code. 

*/
// } Driver Code Ends
// User function Template for C++
class Solution {
private:
    void topoSortDFS(int node, vector<bool>& visited, stack<int>& st, vector<pair<int, int>> adjList[]) {
        visited[node] = true;
        for (auto i : adjList[node]) {
            if (!visited[i.first]) {
                topoSortDFS(i.first, visited, st, adjList);
            }
        }
        st.push(node);
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
        // code here
        // N -> Vertices
        // M -> Edges
        // Creation of ADJ List
        vector<pair<int, int>> adjList[N];
        for (int i = 0; i < M; i++) {
            int vertSrc = edges[i][0];  // Extract the source vertex
            int vertDst = edges[i][1];  // Extract the destination vertex
            int edgeWtt = edges[i][2];  // Extract the edge weight
            adjList[vertSrc].push_back({vertDst, edgeWtt});
        }
        // Topo Sort
        vector<bool> visited(N, false);
        stack<int> st;
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                topoSortDFS(i, visited, st, adjList);
            }
        }
        //Calculating the distance shortest distance from each node to their nearest node
        vector<int> dist(N, 1e9);
        dist[0] = 0;
        while (!st.empty()) {
            int topNode = st.top();
            st.pop();
            for (auto neighbours : adjList[topNode]) {
                int vert = neighbours.first;
                int wtt = neighbours.second;
                if (dist[topNode] + wtt < dist[vert]) {
                    dist[vert] = dist[topNode] + wtt;
                }
            }
        }
        for (int i = 0; i < N; i++) {
            if (dist[i] == 1e9) dist[i] = -1;
        }

        return dist;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends