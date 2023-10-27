#include<bits/stdc++.h>
using namespace std;
/*
Problem Statement: https://leetcode.com/problems/number-of-enclaves/
Solution: DFS
Explanation : Similar to Surrounded_Regions in leetcode.
*/
class Solution {
public:
    int delRow[4] = {-1, 0, 1, 0};
    int delCol[4] = {0, 1, 0, -1};

    void DFS(int i, int j, vector<vector<bool>>& visited, vector<vector<int>>& grid) {
        int rowGrid = grid.size();
        int colGrid = grid[0].size();
        visited[i][j] = true;
        for (int k = 0; k < 4; k++) {
            int tempRow = i + delRow[k];
            int tempCol = j + delCol[k];
            if (tempRow >= 0 && tempRow < rowGrid && tempCol >= 0 && tempCol < colGrid && !visited[tempRow][tempCol] && grid[tempRow][tempCol] == 1) {
                DFS(tempRow, tempCol, visited, grid);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int rowGrid = grid.size();
        if (rowGrid == 0) return 0;
        int colGrid = grid[0].size(); 
        vector<vector<bool>> visited(rowGrid, vector<bool>(colGrid, false));

        for (int i = 0; i < rowGrid; i++) {
            if (!visited[i][0] && grid[i][0] == 1) {
                DFS(i, 0, visited, grid);
            }
            if (!visited[i][colGrid - 1] && grid[i][colGrid - 1] == 1) {
                DFS(i, colGrid - 1, visited, grid);
            }
        }

        for (int j = 0; j < colGrid; j++) {
            if (!visited[0][j] && grid[0][j] == 1) {
                DFS(0, j, visited, grid);
            }
            if (!visited[rowGrid - 1][j] && grid[rowGrid - 1][j] == 1) {
                DFS(rowGrid - 1, j, visited, grid);
            }
        }

        int ctr = 0;

        for (int i = 0; i < rowGrid; i++) {
            for (int j = 0; j < colGrid; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    ctr++;
                }
            }
        }

        return ctr;
    }
};

int main(){
    int rowGrid,colGrid;
    cin>>rowGrid>>colGrid;
    vector<vector<int>> grid(rowGrid,vector<int>(colGrid,0));
    for(int i=0;i<rowGrid;i++){
        for(int j=0;j<colGrid;j++){
            cin>>grid[i][j];
        }
    }
    Solution obj;
    cout<<obj.numEnclaves(grid)<<endl;
    return 0;
}