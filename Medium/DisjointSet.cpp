#include<bits/stdc++.h>
using namespace std;
/*
Disjoint Data Structure is used to find the connected components in a graph.These are used in Kruskal's Algorithm to find the MST of a graph.
The main purpose of this data structure is to find the parent of a node and to check if two nodes are connected or not and to join two nodes or we 
can say that two disjoint sets. 
The terminology used in this data structure is :
1. Find : It is used to find the parent of a node.
2. Union : It is used to join two disjoint sets.
3. isConnected : It is used to check if two nodes are connected or not.
4. Rank : It is the number of nodes in the disjoint set or height of the disjoint set while creating the disjoint set.
5. Path Compression : It is used to reduce the height of the disjoint set while finding the parent of a node. And it's done by the 
    find the ultimate parent of the disjoint set that is the root of the disjoint set and then assigning the parent of the node to the root of the.
    disjoint set.
_____________________________________________________________________________________________________________________________________________________
The union process is done upon 2 things :
1. Rank of the parent of the node.
2. Size of the disjoint set.

_____________________________________________________________________________________________________________________________________________________
For Rank :
Rank is the number of nodes in the disjoint set or height of the disjoint set while 
creating the disjoint set.


*/
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
//Disjoint Data Structure using Size vector it's used to find the size of the disjoint set.
class DisjointSetUsingSize{
    public:
    vector<int> parent;
    vector<int> size;
    DisjointSetUsingSize(int n){
        parent.resize(n);
        size.resize(n);
        for(int i = 0 ; i < n ; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find(int x){
        if(parent[x] == x) return x;
        return (parent[x] = find(parent[x]));
    }
    void union_(int x,int y){
        int parentOfX = find(x);
        int parentOfY = find(y);
        if(size[parentOfX] > size[parentOfY]){
            parent[parentOfY] = parentOfX;
            size[parentOfX] += size[parentOfY];
        }
        else{
            parent[parentOfX] = parentOfY;
            size[parentOfY] += size[parentOfX];
        }
    }
    bool isConnected(int x,int y){
        if(find(x) == find(y)) return true;
        return false;
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    DisjointDataStructureUsingRank ds(n);
    for(int i = 0 ; i < m ; i++){
        int x,y;
        cin>>x>>y;
        ds.union_(x,y);
    }
    int q;
    cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
        if(ds.isConnected(x,y)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
