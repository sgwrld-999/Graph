//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
/*
Problem Name : Euler Circuit And Path
Problem Link : https://practice.geeksforgeeks.org/problems/euler-circuit-and-path/1
Explanation ;
We'll use the following theorem to solve this problem :
1. If all vertices have even degree, the graph contains an Euler circuit.
2. If exactly two vertices have odd degree, the graph contains an Euler path.
3. If graph is not connected, then it does not contain Euler circuit or path.

The above theorem is based on the following facts :
1. In a graph, sum of all degrees is equal to twice the number of edges.
2. In a connected graph, all vertices have even degree if and only if all vertices have even degree.
3. In a connected graph, if exactly two vertices have odd degree, then graph contains an Euler path.

We'll use the 2nd theorem to solve this problem.
*/
// } Driver Code Ends
class Solution {
public:
	int isEulerCircuit(int V, vector<int>adj[]){
	    // Code here
	    vector<int> deg(V,0);
		// Calculating degree of each vertex
	    for(int i = 0 ; i < V ; i++){
	        for(auto it : adj[i]){
	            deg[it]++;
	        }
	    }
		// Checking if all vertices have even degree
	    int res = 0;
	    for(auto it : deg){
	        if(it%2 != 0)res++;
	    }
	    if(res == 0){
	        return 2;
	    }
	    else if(res == 2){
	        return 1;
	    }
	    return 0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.isEulerCircuit(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends