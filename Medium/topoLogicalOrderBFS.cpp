//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
/*
Exaplnation : The instition of this code is related to the definition of the topological sort.
Since in topological order the uv edge is directed from u to v so in the order u comes before v.
Means there is a dependency of v on u. Means no matter what v will always come after u.
So we will maintain an indegree array which will store the number of dependencies of a node.
Why indegree == 0 because if indegree == 0 then there is no dependency of that node on any other node.
And afterwards we will apply BFS and will push all the nodes with indegree == 0 in the queue with some modificationas.
Time complexity : O(V+E)
Space complexity : O(V)
*/
class Solution
{
	public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    int indeg[V]; 
        for(int i = 0 ; i < V ; i++) indeg[i] = 0;
	    for(int i = 0 ; i < V ; i++){
	        for(auto node : adj[i]){
	            indeg[node]++;
	        }
	    }
	    queue<int> q;
        //Jiski indegree 0 hai usko queue mei push kardo
	    for(int i = 0 ; i < V ; i++){
	        if(indeg[i] == 0) q.push(i);
	    }
	    vector<int> topoSort ;
	    //Applying BFS
	    while(!q.empty()){
	        int frontNode = q.front() ;
	        q.pop();
	        topoSort.push_back(frontNode);
	        for(const auto node : adj[frontNode]){
	            indeg[node]--;
	            if(indeg[node] == 0) q.push(node);
	        }
	    }
	    return topoSort;
	}
};

//Check if the order is correct or not
bool check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())return false;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return false;
        }
    }
    return true;
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