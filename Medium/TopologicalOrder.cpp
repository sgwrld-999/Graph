#include <bits/stdc++.h>
using namespace std;

/*
Topolofical sort :
Definition : Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge uv, vertex u comes before v in the ordering.
Topological Sorting for a graph is not possible if the graph is not a DAG.
Examples : 
Graph 1 : 
Input: n = 4, edges = [[1,0],[2,0],[3,1],[3,2]]
linear ordering 1 : 0 -> 1 -> 2 -> 3
linear ordering 2 : 0 -> 2 -> 1 -> 3
Output: [0,1,2,3]

*/
class Solution
{   
    private:
    void DFS(int node,vector<bool>& visited,stack<int>&st,vector<int> adj[]){
        visited[node] = true;
        for(auto i : adj[node]){
            if(!visited[i]){
                DFS(i,visited,st,adj);
            }
        }
        st.push(node);
    }
	public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<bool> visited(V,false);
	    stack<int>st ;
	    for(int i = 0 ; i < V ; i++){
	        if(!visited[i]){
	            DFS(i,visited,st,adj);
	        }
	    }
	    vector<int>ans;
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};

int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}