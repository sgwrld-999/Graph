//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/*
Problem name : Articulation Points - 1 
Problem link : https://practice.geeksforgeeks.org/problems/articulation-points/1
Explanation :
We've to find the articulation points in the graph. The question is similar to the question of finding bridges in the graph.
But the difference in the code is that we've to check if the node is root node or not. If the node is root node then we've to check
if the node has more than 1 child or not. If the node is not root node then we've to check if the lowest time of insertion of a node
in DFS tree is greater than the time of insertion of the node or not. If the lowest time of insertion of a node in DFS tree is greater 
than the time of insertion of the node then we'll add that node to the articulation points.

And the reasion we are storing the time of insetion instead of the lowest time of insertion of a node in DFS tree is that we want to
check if the adjacent nodes have same time it'll help to track that if there is an another path to reach that node or if there is a way to 
reach the parent node of the the node via that node or not.

For example : 
If let's say in a graph the articulation point is 2 and parent of 2 is 3 and the child is 4.
So after return a call of the 4 if we check that the lowest time of 4 is 3 and parent of 4 is 2 means it's an articulation point as
there is no other way to reach 3 except the going through 2. So, we'll add 2 to the articulation points.
*/
// } Driver Code Ends
//User function Template for C++

class Solution {
private:
    int timer = 1;
    void DFS(int node, int parent, int tIsn[], int lT[], vector<bool> &visited, vector<bool> &mark, vector<int> adj[]) {
        visited[node] = true;
        tIsn[node] = timer;
        lT[node] = timer;
        timer++;
        int child = 0;
        for (auto it : adj[node]) {
            if (it == parent)
                continue;

            if (!visited[it]) {
                DFS(it, node, tIsn, lT, visited, mark, adj);
                lT[node] = min(lT[node], lT[it]);
                if (lT[it] >= tIsn[node] && parent != -1) {
                    mark[node] = true;
                }
                child++;
            } else {
                lT[node] = min(lT[node], tIsn[it]);
            }
        }
        if (child > 1 && parent == -1)
            mark[node] = true;
    }

public:
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        // Code here
        int timeOfInsertion[V];
        int lowTime[V];
        vector<bool> visited(V, false);
        vector<bool> mark(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                DFS(i, -1, timeOfInsertion, lowTime, visited, mark, adj);
            }
        }
        vector<int> ans;
        for (int i = 0; i < V; i++) {
            if (mark[i]) {
                ans.push_back(i);
            }
        }
        return ans.empty() ? vector<int>{-1} : ans;
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
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends