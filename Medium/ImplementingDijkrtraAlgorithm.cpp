//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/*
We are not using the queue here because if we use queue then we have to travesre or explore all the path 
and figure out the minimum paths. So more like a it's Brute Force approach.
Time complexity : O(V^2)
space complexity : O(V)

But If we use the priority queue then we'll be able to remove the unneccessary paths and we'll be able to
find the shortest path.
How? 
Because we'll be storing the distance of each node from the source node and we'll be updating the distance
if we find the shorter path. Means if we find the shorter path then we'll update the distance of that node and since we are storing in the 
priority queue so it'll automatically remove the unneccessary paths as the value which is greater will be at the back 
of the queue and minimum will be at the front. After we remove the minimum element the next shortest path will be at the front.
So we'll be able to find the shortest path.
Time complexity : O(ElogV) as for each node we'll be traversing all the edges and we'll be removing the unneccessary paths.
Space complexity : O(V) as we are storing the distance of each node from the source node.
*/
// } Driver Code Ends
class Solution {
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        // Code here
        /*
        We have given an adjList as a vector of vectors array 
        0 -> {0 or 1, 1},{0 or 2, 6} 
        Each index denoting the node, and the vectors are denoting the edge from that
        node to the neighbor node with.
        V stands for the Number of Vertices
        */
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, INT_MAX); // Distance vector which will store the distances
        // Marking the distance of Source node S
        dist[S] = 0;
        // Pushing into the priority queue
        pq.push({0, S});
        // Similar to BFS but with slight modification
        while (!pq.empty()) {
            int distance = pq.top().first;
            int frontNode = pq.top().second;
            pq.pop();

            for (auto neighbors : adj[frontNode]) {
                int currNode = neighbors[0];      // 0th index element representing the Node
                int currNodeWt = neighbors[1];    // 1st index element representing the weight of the edge
                if (distance + currNodeWt < dist[currNode]) {
                    dist[currNode] = distance + currNodeWt;
                    pq.push({dist[currNode], currNode});
                }
            }
        }
        return dist;
    }
};

class Solution2UsingSet
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        //Same approach but this time we'll use set it'll remove the element in log(n) time
        // and remove the unneccessary path traversal.
        set<pair<int,int>> setPq;
        vector<int> dist(V,1e9);
        setPq.insert({0,S});
        dist[S] = 0 ;
        while(!setPq.empty()){
            auto firstEle = *(setPq.begin());
            int frontNodeWt = firstEle.first;
            int frontNode = firstEle.second;
            setPq.erase(firstEle);
            for(auto nieghbours : adj[frontNode]){
                int currNode = nieghbours[0];
                int currNodeWt = nieghbours[1];
                if(dist[currNode] > currNodeWt + frontNodeWt){
                    setPq.erase({dist[currNode],currNode});
                    dist[currNode] = currNodeWt + frontNodeWt;
                    setPq.insert({currNodeWt + frontNodeWt,currNode});
                }
            }
        }
        return dist;
    }
};
//{ Driver Code Starts.
/*
Input format : 
First line contains T, number of test cases. Each test case in its first line contains two positive integers V and E where 'V' is the number of vertices and 'E' is number of edges in graph. Next 'E' line contains three positive integers u, v and w, which denotes that there is an edge between u and v and weight of edge is w.
*/

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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends