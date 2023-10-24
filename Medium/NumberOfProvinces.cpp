#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<int, list<int>> adjList;

    void DFS(int node, vector<bool>& visited) {
        visited[node] = true;
        for (auto it : adjList[node]) {
            if (!visited[it])
                DFS(it, visited);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int vertices = isConnected.size();
        vector<bool> visited(vertices, false);
        
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        int ctr = 0;
        for (int i = 0; i < vertices; i++) {
            if (!visited[i]) {
                ctr++;
                DFS(i, visited);
            }
        }
        return ctr;
    }
};

int main() {
    Solution obj;
    vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
    cout << obj.findCircleNum(isConnected) << endl;
}