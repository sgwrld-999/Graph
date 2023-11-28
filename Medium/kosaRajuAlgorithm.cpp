//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
/*
Problem name : Strongly Connected Components (Kosaraju's Algo)
Problem link : https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1#
Algorithm :
1. Do DFS and store the nodes in the stack in the order of their finish times.
2. Transpose the graph.
3. Do DFS on the transpose of the graph and count the number of SCCs.
Explanation : 
Doing DFS on the graph and storing the nodes in the stack in the order of their finish times because we want to
traverse the graph in the order of their finish times. To store the value in Topoplogical order it'll simplfy the 
travaers of the grph in the order of their finish times.

Reverse the graph because we want to stick to only one SCC. If we don't reverse the graph then we'll get all the SCCs.

Next DFS is to traverse the transpose of the graph and count the number of SCCs.


Time Complexity : O(V + E)
Space Complexity : O(V + E)


*/
// } Driver Code Ends
class Solution {
private:
    // First DFS to fill the stack with nodes in the order of their finish times.
    void DFS(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
        visited[node] = true;
        for (auto adjNode : adj[node]) {
            if (!visited[adjNode]) {
                DFS(adjNode, adj, visited, st);
            }
        }
        st.push(node);
    }

    // Second DFS to traverse the transpose of the graph and count SCCs.
    void DFS1(int node, vector<vector<int>>& adjT, vector<bool>& visited) {
        visited[node] = true;
        for (auto adjNode : adjT[node]) {
            if (!visited[adjNode]) {
                DFS1(adjNode, adjT, visited);
            }
        }
    }

public:
    int kosaraju(int V, vector<vector<int>>& adj) {
        vector<bool> visited(V, false);
        stack<int> st;

        // First DFS to fill the stack with nodes in the order of their finish times.
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                DFS(i, adj, visited, st);
            }
        }

        // Transpose the graph.
        vector<vector<int>> adjT(V);
        for (int i = 0; i < V; i++) {
            visited[i] = false;
            for (auto it : adj[i]) {
                adjT[it].push_back(i);
            }
        }

        int ctr = 0;

        // Second DFS to traverse the transpose of the graph and count SCCs.
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!visited[node]) {
                ctr++;
                DFS1(node, adjT, visited);
            }
        }

        return ctr;
    }
};


//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends