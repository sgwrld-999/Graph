#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool DFS(int node, vector<int>& visited, vector<int>& pathVisited, vector<vector<int>>& graph, vector<int>& check) {
        visited[node] = 1;
        pathVisited[node] = 1;
        check[node] = 0;
        for (auto neighbor : graph[node]) {
            if (!visited[neighbor]) {
                if (DFS(neighbor, visited, pathVisited, graph, check)) {
                    check[node] = 0;
                    return true;
                }
            } else if (pathVisited[neighbor]) {
                check[node] = 0;
                return true;
            }
        }
        check[node] = 1;
        pathVisited[node] = 0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> visited(V, 0);
        vector<int> pathVisited(V, 0);
        vector<int> check(V, 0);
        vector<int> safeNodes;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (DFS(i, visited, pathVisited, graph, check)) {
                    continue;
                }
            }
        }
        for(int i = 0 ; i < V ; i++){
            if(check[i] == 1){
                safeNodes.push_back(i);
            }
        }
        sort(safeNodes.begin(), safeNodes.end());

        return safeNodes;
    }
};

int main(){
    int V, E;
    cin >> V >> E;
    vector<vector<int>> graph(V);
    for(int i = 0 ; i < E ; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    Solution s;
    vector<int> safeNodes = s.eventualSafeNodes(graph);
    for(auto node : safeNodes){
        cout << node << " ";
    }
    cout << endl;
    return 0;
}