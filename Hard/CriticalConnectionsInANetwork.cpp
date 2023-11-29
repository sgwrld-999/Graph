#include<bits/stdc++.h>
using namespace std;
/*
Problem Name : Critical Connections In A Network
Problem Link : https://practice.geeksforgeeks.org/problems/critical-connections/1
Explanation :
The question is saying to us to find such edges such that after removing that edge the graph becomes disconnected
or the graph seperated in components. We can use the concept of bridges to solve this problem.

We'll use the following DS to solve the problem : 
1. visited[] : To keep track of visited nodes.
2. timeOfInsertion[] : To keep track of time of insertion of a node in DFS tree or at what step we've 
    reached that node or server. It'll be used to find the lowest time of insertion of a node in DFS tree.
3. lowTime[] : To keep track of the lowest time of insertion of a node in DFS tree or at what step we've
    reached that node or server. It'll be used check if the adjacent nodes have same time it'll help to track 
    that if there is an another path to reach that node.
4. bridges[][] : To store the bridges or critical connections.
5. timer : To keep track of time of insertion of a node in DFS tree.

The algorithm is as follows :
1. We'll start DFS from node 0 and we'll keep track of time of insertion of a node in DFS tree and lowest time
    of insertion of a node in DFS tree.
2. If the adjacent node is not visited then we'll call DFS on that node and we'll update the lowest time of
    insertion of a node in DFS tree.
3. If the adjacent node is visited then we'll update the lowest time of insertion of a node in DFS tree.
4. If the lowest time of insertion of a node in DFS tree is greater than the time of insertion of the node
    then we'll add that edge to the bridges[][].
5. We'll return the bridges[][].

*/
class Solution {
private:
    int timer = 1 ; // To keep track of time of insertion of a node in DFS tree
    void DFS(int node,int parent,vector<bool>& visited,vector<int> adj[],int tIn[],int lT[],vector<vector<int>>&bridges){
        visited[node] = true;
        tIn[node] = timer ;
        lT[node]  = timer ;
        timer++ ;
        for(auto it : adj[node]){
            if(it == parent) continue; // If the adjacent node is parent then we'll continue as we don't want to go back to parent
            if(!visited[it]){
                DFS(it,node,visited,adj,tIn,lT,bridges);
                lT[node] = min(lT[node],lT[it]);// Updating the lowest time of insertion of a node in DFS tree
                if(lT[it] > tIn[node]){// Checking if the lowest time of insertion of a node in DFS tree is greater than the time of insertion of the node
                    bridges.push_back({it,node});
                }
            }else{// If the adjacent node is visited then we'll update the lowest time of insertion of a node in DFS tree
                lT[node] = min(lT[node],lT[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<bool>visited(n,false);
        vector<int> adj[n];
        for(auto it :connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int timeOfInsertion[n];
        int lowTime[n];
        vector<vector<int>> bridges;
        DFS(0,-1,visited,adj,timeOfInsertion,lowTime,bridges);
        return bridges;

    }
};

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int V, E;
        cin >> V >> E;
        vector<vector<int>>connections;
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            connections.push_back({u,v});
        }
        Solution obj;
        vector<vector<int>>ans = obj.criticalConnections(V,connections);
        for(auto it : ans){
            cout << it[0] << " " << it[1] << endl;
        }
    }
    return 0;
}