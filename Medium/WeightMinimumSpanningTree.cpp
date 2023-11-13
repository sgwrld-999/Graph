//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/*
Problem Name : Minimum Spanning Tree
Problem Link : https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
Problem Statement: Given a weighted, undirected and connected graph of V vertices and E edges. 
                   The task is to find the sum of weights of the edges of the Minimum Spanning Tree.

Expected Time Complexity: O(ElogV).
Expected Auxiliary Space: O(V^2).

Exaplantion : 
We are using Prim's algorithm to find the minimum spanning tree.
Prim's algortihm states that we start from any node and then we find the minimum weight edge from that node.
Then we find the minimum weight edge from the nodes that are connected to the previous node and so on.

Pris's algorithm uses Greedy approach i.e is selecting the minimum weight edge at each step and then adding it to the MST. 
To implement the Greedy approach we are using priority queue which stores the edges in the increasing order of their weights.

Similar to the BFS we are using a visited array to keep track of the nodes that are already visited.

But this time we are using a priority queue to store the edges in the increasing order of their weights.

*/
// } Driver Code Ends
class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        vector<bool> visited(V, false);

        pq.push({0, 0}); 
        int sum = 0;

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            int currWeight = it.first; 
            int currNode = it.second;  

            if (visited[currNode])
                continue;

            visited[currNode] = true;

            sum += currWeight;

            for (auto node : adj[currNode])
            {
                int adjNode = node[0];
                int adjNodeWeight = node[1];

                if (!visited[adjNode])
                {
                    pq.push({adjNodeWeight, adjNode}); // edgeWeight, node
                }
            }
        }
        return sum;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends