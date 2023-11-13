//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
/*
problem name : Number of ways to arrive at destination
Problem link : https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/
Explanation:
The question is asking us to find the number of ways to reach the last node from the first node with the shortest distance.
So, it's a graph problem but also we have to store the number of ways to reach a node.
We can say that it's a GRAPH + DP problem. As we have to explore all the paths and also find the minimum and store it 
as for an example 2 nodes u and v are connected by 3 edges and 2 different paths are there to reach from u to v.
u -> x -> y -> v
u -> z -> -> x -> y -> v
Number of ways to reach x is 2.
Number of ways to reach y is to get reach x first and then from x to y. means 2+1.
Similarliy number of ways to reach v is 2+1+1.
Same logic will be applied in the given question.

To do that we'll use Dijkstra's algorithm + DP(An 1D array to store the number of ways to reach a node).
*/
// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // Create the adjacency list
        vector<pair<int, int>> adjList[n];

        for (auto node : roads) {
            adjList[node[0]].push_back({node[1], node[2]});
            adjList[node[1]].push_back({node[0], node[2]});
        }

        // {Node, Distance}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0, 0});

        // Distance array
        vector<long long> dist(n, LLONG_MAX); 

        dist[0] = 0;

        vector<int> numOfWays(n, 0);
        numOfWays[0] = 1;

        int mod = (int)(1e9 + 7);

        while (!pq.empty()) {
            
            auto it = pq.top();
            pq.pop();

            int currNode = it.first ;  
            int currDist = it.second; 
            
            for (auto node : adjList[currNode]) {
                
                int neighbourNode = node.first;
                int neighbourWeight = node.second;

                // If we find a weight of the edge is minimum
                // and the below condition is satisfying, which means
                // we've reached this way the first time;
                
                if (currDist + neighbourWeight < dist[neighbourNode]) {
                    dist[neighbourNode] = currDist + neighbourWeight;
                    numOfWays[neighbourNode] = numOfWays[currNode];

                    pq.push({neighbourNode, currDist + neighbourWeight }); \
                } else if (currDist + neighbourWeight == dist[neighbourNode]) {
                    numOfWays[neighbourNode] = (numOfWays[currNode] + numOfWays[neighbourNode]) % mod;
                }
            }
        }

        return numOfWays[n - 1]%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends