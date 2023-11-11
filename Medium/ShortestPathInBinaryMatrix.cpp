#include<bits/stdc++.h>
using namespace std;

/*
Problem name : Shortest Path in Binary Matrix
Problem link : https://leetcode.com/problems/shortest-path-in-binary-matrix/
Explanation: 
We to reach the bottom right corner of the matrix from the top left corner.
We can move in 8 directions from a cell.
We can use BFS or Dijkstra algorithm to find the shortest path.
We will use BFS here because the advantage that provides is that we sort the 
distances acoording to the distance from the source. But we 
don't need that here because the values is getting increment by one and 
the moving direction cost us the same so we don't need the priority queue here simple BFS 
will do the job.
*/
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1) return -1;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int, pair<int, int>>> que;
        dist[0][0] = 1;
        que.push({1, {0, 0}});
        while (!que.empty()) {
            auto it = que.front();
            que.pop();
            int currDist = it.first;
            int currRow = it.second.first;
            int currCol = it.second.second;
            for (int row = -1; row < 2; row++) {
                for (int col = -1; col < 2; col++) {
                    int newRow = currRow + row;
                    int newCol = currCol + col;

                    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n &&
                        grid[newRow][newCol] == 0 && currDist + 1 < dist[newRow][newCol]) {
                        dist[newRow][newCol] = currDist + 1;
                        que.push({currDist + 1, {newRow, newCol}});
                    }
                }
            }
        }
        return (grid[n - 1][n - 1] == 0 && dist[n - 1][n - 1] != INT_MAX) ? dist[n - 1][n - 1] : -1;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> grid = {{0,0,0},{1,1,0},{1,1,0}};
    cout << sol.shortestPathBinaryMatrix(grid) << endl;
    return 0;
}