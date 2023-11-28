#include<bits/stdc++.h>
using namespace std;
/*
Problem name : Making A Large Island
Problem link : https://leetcode.com/problems/making-a-large-island/
Exaplanation :
The question is saying to us find the largest island that can be formed by changing only one 0 to 1.
The question can be solved using disjoint data structure. 
As first find all the connected componets and then change 0 to 1 and checking in all 
direction if there is a island connected to it or not. If there is a island connected to it then
find the size of the island and add it to the size of the current island and update the max size.
Time Complexity : O(n^2)
Space Complexity : O(n^2)

*/
class DisjointDataStructureUsingRank {
public:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;

    DisjointDataStructureUsingRank(int n) {
        parent.resize(n);
        rank.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return (parent[x] = find(parent[x]));
    }

    void union_(int x, int y) {
        int parentOfX = find(x);
        int parentOfY = find(y);
        if (parentOfX != parentOfY) {
            if (rank[parentOfX] > rank[parentOfY]) {
                parent[parentOfY] = parentOfX;
                size[parentOfX] += size[parentOfY];
            }
            else {
                parent[parentOfX] = parentOfY;
                size[parentOfY] += size[parentOfX];
                if (rank[parentOfX] == rank[parentOfY]) {
                    rank[parentOfY]++;
                }
            }
        }
    }

    bool isConnected(int x, int y) {
        return (find(x) == find(y));
    }
};

class Solution {
public:
    bool isValid(int newRow, int newCol, int n) {
        return (newRow < n && newRow >= 0 && newCol < n && newCol >= 0);
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointDataStructureUsingRank ds(n * n);

        // Step 1: Connecting the components
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0) continue;
                int drow[] = {-1, 0, 1, 0};
                int dcol[] = {0, -1, 0, 1};
                for (int i = 0; i < 4; i++) {
                    int newRow = row + drow[i];
                    int newCol = col + dcol[i];
                    if (isValid(newRow, newCol, n) && grid[newRow][newCol] == 1) {
                        int nodeNum = row * n + col;
                        int adjNodeNum = newRow * n + newCol;
                        ds.union_(nodeNum, adjNodeNum);
                    }
                }
            }
        }

        // Step 2 : Finding the largest component
        int maxSize = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) continue;
                int drow[] = {-1, 0, 1, 0};
                int dcol[] = {0, -1, 0, 1};
                set<int> comp;
                for (int i = 0; i < 4; i++) {
                    int newRow = row + drow[i];
                    int newCol = col + dcol[i];
                    if (isValid(newRow, newCol, n) && grid[newRow][newCol] == 1) {
                        comp.insert(ds.find(newRow * n + newCol));
                    }
                }
                int sizeTotal = 1;
                for (auto it : comp) {
                    sizeTotal += ds.size[it];
                }
                maxSize = max(maxSize, sizeTotal);
            }
        }
        
        for (int cellNum = 0; cellNum < n * n; cellNum++) {
            maxSize = max(maxSize, ds.size[ds.find(cellNum)]);
        }

        return maxSize;
    }
};

int main(){
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){
            cin >> grid[row][col];
        }
    }
    Solution sol;
    cout << sol.largestIsland(grid) << endl;
    return 0;
}