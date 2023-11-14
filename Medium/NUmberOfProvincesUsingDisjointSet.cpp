//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/*
Problem Name : Number of Provinces
Problem Link : https://practice.geeksforgeeks.org/problems/number-of-provinces/1
Explnation : This is the same problem as the number of connected components in a graph.
Form the disjoint set prepective we can say that we have to just calculate the number of 
Ulitmate parent or root nodes in the disjoint set.

Just create the disjoint set and then count the number of root nodes in the disjoint set.

And return the count of the root nodes in the disjoint set.
*/
// } Driver Code Ends
//User function Template for C++

class DisjointDataStructureUsingRank{
    public:
    vector<int> parent;
    vector<int> rank;
    DisjointDataStructureUsingRank(int n){
        parent.resize(n);
        rank.resize(n);
        for(int i = 0 ; i < n ; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int find(int x){
        if(parent[x] == x) return x;
        return (parent[x] = find(parent[x]));
    }
    void union_set(int x,int y){
        int parentOfX = find(x);
        int parentOfY = find(y);
        if(rank[parentOfX] > rank[parentOfY]){
            parent[parentOfY] = parentOfX;
        }
        else{
            parent[parentOfX] = parentOfY;
            if(rank[parentOfX] == rank[parentOfY]){
                rank[parentOfY]++;
            }
        }
    }
    bool isConnected(int x,int y){
        if(find(x) == find(y)) return true;
        return false;
    }
};


class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        //Creation of the disjoint set;
        DisjointDataStructureUsingRank ds(V);
        
        for(int i = 0 ; i < V ; i++){
            for(int j = 0 ; j < V ; j++){
                if(adj[i][j] == 1) ds.union_set(i,j);
            }
        }
        int countPar = 0 ;
        for(int i = 0 ; i < V ; i++){
            if(ds.parent[i] == i) countPar++;
        }
        
        return countPar ;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends