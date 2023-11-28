#include<bits/stdc++.h>
using namespace std;

/*
Problwm name : Most Stones Removed with Same Row or Column
Problem link : https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
Exaplanation :
IMPORTANT : Dynamic Graphs -> Disjoint Data Structure
The idea behind this problem is to find the number of connected components in the graph.
As question state that we can remove the stones if they are in same row or column. And if we considered row as 
on set or node and column as another set or node then we can say that if there is a stone in same row or column
then we can remove that stone. So, we can say that if there is a stone in same row or column then we can say that
they are connected. So, we can find the number of connected components in the graph and then we can say that
we can remove the stones equal to number of connected components - 1. As we can't remove the last stone.
Derivation :
Let's say there are n stones and m connected components and in that m connected components there we have remove all the stones
except one stone in each connected component. Also 
C1 + C2 + C3 + C4 + C5 + C6 + C7 + C8 + C9 ... + Cm = n
where C1, C2, C3, C4, C5, C6, C7, C8, C9 ... Cm are the number of stones in each connected component.
Also we have to remove all the stones except one stone in each connected component. So, we can say that
C1 - 1 + C2 - 1 + C3 - 1 + C4 - 1 + C5 - 1 + C6 - 1 + C7 - 1 + C8 - 1 + C9 - 1 ... + Cm - 1 
(C1 + C2 + C3 + C4 + C5 + C6 + C7 + C8 + C9 ... + Cm) - (1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 ... + 1) = n - m
So the asnwer is n - m.

Time Complexity : O(n)
Space Complexity : O(n)

*/
class DisjointSet {
    vector<int> rank, parent, size;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        //Finding the maximum row and column value as we have to create the disjoint set of size maxRow + maxCol + 1
        int maxRow = 0;
        int maxCol = 0;
        for (auto it : stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        int n = stones.size();
        DisjointSet ds(maxRow + maxCol + 1);
        //Creating a map of stone nodes so that we can find the number of connected components in the graph or to find the number of connected components in the disjoint set
        unordered_map<int, int> stoneNodes;
        for (auto it : stones) {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1; // Formula to convert the column value to a unique value of disjoint set
            ds.unionBySize(nodeRow, nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }

        int cnt = 0;
        for (auto it : stoneNodes) {
            if (ds.findUPar(it.first) == it.first) { // If the parent of the node is same as the node then it is a connected component
                cnt++;
            }
        }
        return n - cnt;
    }
};

int main(){
    vector<vector<int>> stones = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    Solution sol;
    cout << sol.removeStones(stones) << endl;
    return 0;
}