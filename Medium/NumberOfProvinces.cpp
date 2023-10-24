#include<bits/stdc++.h>
using namespace std;
//Application of DFS that is to find the number of connected components in a graph
//Time complexity : O(N) * O(V + 2E) wrong time complexity
//Space complexity : O(V + 2E) + O(V) because only once the DFS will be called for each node
class Solution {
public:
    map<int, list<int>> adjList;
    //Simnple DFS
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
        // Create Adjacency List or Convert Adjacency Matrix to Adjacency List
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                if (isConnected[i][j] == 1 && i != j) {// i != j is important because we don't want to add
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        int ctr = 0;
        for (int i = 0; i < vertices; i++) {
            if (!visited[i]) {
                ctr++;// Increment the counter if we find a new component sice DFS will mark every connected node as visited of that componet and we don't want to count them again
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