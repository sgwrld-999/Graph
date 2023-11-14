#include<bits/stdc++.h>
using namespace std;

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
    void union_(int x,int y){
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

