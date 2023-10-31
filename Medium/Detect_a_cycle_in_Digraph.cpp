#include <bits/stdc++.h>
using namespace std;
/*
Problem link : https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

Explanation : Since the graph is directed, we can't use the same approach as we used in undirected graph.
Because in the undirected graph we can go back to the parent node, but in directed graph we can't go back to the parent node. As there can be
only way or path to go from one node to another node.
So we need a diffrenet approach to solve this problem.
And the approach is that since the graph is directed and we can't go back to the parent node, so we need to find a node which is already visited
and also we need to find the path of the node which is already visited.
So we need to store the way to find the path of the node which is already visited as well the path of the node which is currently call is made.

*/
class Solution {
public:
    bool DFS(int node, vector<bool>& visited, vector<bool>& pathVisited, vector<int> adj[]) {
        visited[node] = true;
        pathVisited[node] = true;
        for (auto neighbors : adj[node]) {
            if (!visited[neighbors]) {
                if (DFS(neighbors, visited, pathVisited, adj)) {
                    return true;
                }
            } else if (pathVisited[neighbors]) {
                return true;
            }
        }
        pathVisited[node] = false;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        vector<bool> pathVisited(V, false);
        for (int node = 0; node < V; node++) {
            if (!visited[node]) {
                if (DFS(node, visited, pathVisited, adj)) {
                    return true;
                }
            }
        }
        return false;
    }
};


int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}