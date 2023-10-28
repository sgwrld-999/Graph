#include<bits/stdc++.h>
using namespace std;
/* 
Problem : Given an undirected graph, return true if and only if it is bipartite.
A graph is bipartite if we can split it's set of nodes into two independent subsets A and B such that every edge in the graph has one node in A
and another node in B.
Or in other terms we can say that a graph is bipartite if we can color it's nodes such that no two adjacent nodes have the same color.
Properties of Bipartite Graphs:
1. A bipartite graph is a graph that can be colored with two colors such that no two adjacent vertices of the graph are colored with the same color.
2. A bipartite graph is a graph that does not contain any odd-length cycles.
3. A graph is bipartite if and only if it is 2-colorable.

Algorithm: BFS but instead of using a visited array we use a color array to keep track of the color of the nodes.

*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool DFS(int node,int colour , vector<vector<int>>& graph , vector<int>& visited){
        visited[node] = colour ;
        for(const auto i : graph[node]){
            if(visited[i] == -1){
                if(DFS(i,1-colour,graph,visited) == false)
                    return false;
            }
            else if(visited[i] == colour)
                return false;
        }
        return true;
    }
    
    bool BFS(int node , vector<vector<int>>& graph , vector<int>& visited){
        queue<int> que ;
        que.push(node);

        while(!que.empty()){
            int frontNode = que.front();
            que.pop();
            for(const auto i : graph[frontNode]){
                if(visited[i] == -1){
                    que.push(i);
                    visited[i] = 1 - visited[frontNode];
                }
                else if(visited[frontNode] == visited[i]){
                    return false;
                }
            }
        }
        return true;

    }
    bool isBipartite(vector<vector<int>>& graph) {
        int sizeOfGraph = graph.size();
        vector<int> visited(sizeOfGraph,-1);
        //For BFS
        // for(int i = 0 ; i < sizeOfGraph ; i++){
        //     if(visited[i] == -1){
        //         visited[i] = 0 ;
        //         if(BFS(i,graph,visited) == false)
        //             return false;
        //     }
        // }
        //For DFS
        for(int i = 0 ; i < sizeOfGraph ; i++){
            if(visited[i] == -1){
                if(DFS(i,0,graph,visited) == false)
                    return false;
            }
        }
        return true ;
    }
};

int main(){
    Solution s ;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cout << s.isBipartite(graph) << endl;
    return 0 ;
}