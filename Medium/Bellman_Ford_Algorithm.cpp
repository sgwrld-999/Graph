//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
/*
Problem link : https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1#
Problem Name : Negative weight cycle
Description : Given a graph, the task is to check if it contains a negative weight cycle or not.
Exaplanation : 
We use bellman ford algorithm as it can detect negative cycles in a graph.

How? 
We run the algorithm for V-1 iterations and then check if there is any edge which can be relaxed further.
Relaxing an edge means that we can reach the terminal node from the initial node in a lesser distance than the current distance.

Why we run the algorithm for V-1 iterations?
Because the maximum number of edges in a graph is V-1. As Bellman is an extension of Dijktra and Dijkstra is 
an extension of BFS, we can say that the maximum number of edges in a graph is V-1 as If we apply BFS on a
graph the resultant will be a tree and the maximum number of edges in a tree is V-1.

We will iterate one more time after V-1 iterations to check if there is any edge which can be relaxed further.
If we can relaxed furhter then there is a negative cycle in the graph.
How?
If we can relaxed further then it means that we can reach the terminal node from the initial node in a lesser distance than the current distance.
And if we can reach the terminal node from the initial node in a lesser distance than the current distance then there is a negative cycle in the graph.
Means there is an edge which can be relaxed further or have a negative weight.

_________________________________________________________________________________________________________________________________________________
Algorithm:
1. Create a distance array of size V and initialize it with infinity.
2. Initialize the distance of the source node with 0.
3. Iterate V-1 times and relax all the edges.
4. Iterate one more time and check if there is any edge which can be relaxed further.  
5. If there is any edge which can be relaxed further then there is a negative cycle in the graph.
_________________________________________________________________________________________________________________________________________________
*/
class Solution {
public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        //Distance storing array
        vector<int> dist(V, 1e8); 
        dist[S] = 0; // Distance from source to itself is always 0

        // V-1 Iterations
        for (int i = 0; i < V - 1; i++) {
            for (const auto& edge : edges) {
                int initial = edge[0];
                int terminal = edge[1];
                int edgeWeight = edge[2];
                // We'll check if the weight to reach the initial
                // node adding to the current edge weight is lesser than
                // to reach the terminal node
                if (dist[initial] + edgeWeight < dist[terminal] && dist[initial] != 1e8) {
                    dist[terminal] = dist[initial] + edgeWeight;
                }
            }
        }

        // Check for negative cycles
        for (const auto& edge : edges) {
            int initial = edge[0];
            int terminal = edge[1];
            int edgeWeight = edge[2];
            if (dist[initial] + edgeWeight < dist[terminal] && dist[initial] != 1e8) {
                // If this condition is satisfied, there is a negative cycle
                return {-1};
            }
        }

        return dist;
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends