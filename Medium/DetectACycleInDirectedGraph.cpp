#include <bits/stdc++.h>
using namespace std;
/*
Explnation : 
In topological order there a dependency of one node on another node.
Means if there is a uv edge then u comes before v in the topological order.
So we will maintain an indegree array which will store the number of dependencies of a node.
Now but due to there having a cycle there will be a node which will be dependent on itself or 
there will be a node which will be dependent on a node which is dependent on that node.

So if we store the nodes then we will get the nodes which are dependent on themselves or means one cyclic node wil be 
repeated twice.

*/
class Solution
{
	public:
	bool topoSort(int V, vector<int> adj[]) 
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
	    return ((topoSort.size() == V) ? true : false);
	}
};

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
        bool res = obj.topoSort(N, adj);
        if(res)
            cout << "1" << endl;
        else
            cout << "0" << endl;
    }
    
    return 0;
}