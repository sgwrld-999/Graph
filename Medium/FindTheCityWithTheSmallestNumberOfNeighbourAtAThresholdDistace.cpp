#include<bits/stdc++.h>
using namespace std;

/*
Problem Name : Find the city with the smallest number of neighbors at a threshold distance
Problem link : https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
Description : There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti]
Explanantion :
The question is to find a node which is maximum and from that node some node is reachable 
within the given distanceThreshold. If its posiible than return that node else -1.
*/
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int, int>> adjList[n];

        for (auto edge : edges) {
            adjList[edge[0]].push_back({edge[1], edge[2]});
            adjList[edge[1]].push_back({edge[0], edge[2]});
        }

        int idx = -1;
        int ans = 1e8;

        for (int i = 0; i < n; i++) {
            queue<pair<int, int>> que;
            que.push({i, 0});

            vector<int> dist(n, 1e8);
            dist[i] = 0;

            while (!que.empty()) {
                auto it = que.front();
                que.pop();

                int currNode = it.first;
                int currWeight = it.second;

                for (auto neighbors : adjList[currNode]) {
                    int newNode = neighbors.first;
                    int newWeight = neighbors.second;

                    if (currWeight + newWeight < dist[newNode]) {
                        dist[newNode] = currWeight + newWeight;
                        que.push({newNode, currWeight + newWeight});
                    }
                }
            }

            int count = 0;
            for (int j = 0; j < n; j++) {
                if (dist[j] <= distanceThreshold) {
                    count++;
                }
            }

            if (count <= ans) {
                ans = count;
                idx = max(i, idx);
            }
        }

        return idx;
    }
};

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n, m, distanceThreshold;
        cin >> n >> m >> distanceThreshold;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        cout << obj.findTheCity(n, edges, distanceThreshold) << "\n";
    }
    return 0;
}