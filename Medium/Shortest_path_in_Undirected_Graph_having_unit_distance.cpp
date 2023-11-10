//{ Driver Code Starts
// Initial Template for C++
/*
The intution behind this problem is that we can use BFS to find the shortest path from source to all other nodes.
We are exploring all the paths and chosing the shortest one for that pariticular node only. But 
we are not sure that the path we are choosing is the shortest path for all the nodes. So, we are using BFS to explore all
the paths and then choosing the shortest one for that particular node only.

*/


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {
        vector<vector<int>> adjList(N);
        for (int idx = 0; idx < M; idx++) {
            adjList[edges[idx][0]].push_back(edges[idx][1]);
            adjList[edges[idx][1]].push_back(edges[idx][0]);
        }

        vector<int> dist(N, 1e9);
        queue<pair<int, int>> que;
        que.push({src, 0});
        dist[src] = 0; 

        while (!que.empty()) {
            int frontNode = que.front().first;
            int frontNodeWt = que.front().second;
            que.pop();
            
            for (auto node : adjList[frontNode]) {
                if (frontNodeWt + 1 < dist[node]) {
                    dist[node] = frontNodeWt + 1;
                    que.push({node, dist[node]});
                }
            }
        }
        for (int idx = 0; idx < N; idx++) {
            if (dist[idx] == 1e9) {
                dist[idx] = -1;
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
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends