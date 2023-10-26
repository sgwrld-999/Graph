#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //The question is the same as FloodFill problem but with a little modification that was 
    // we have to check if all the fresh oranges are rotten or not and only then return the time
    // otherwise return -1
    //And also we've to apply BFS on all the rotten oranges at the same time
    //Not in one go like we did in FloodFill problem but one by one in a queue
    //Becuase we have to count the BFS calls needed to make all the fresh oranges rotten
    int orangesRotting(vector<vector<int>>& grid) {
        int gridRow = grid.size();
        int gridCol = grid[0].size();
        int ctrFresh = 0;
        vector<vector<int>> visited(gridRow, vector<int>(gridCol, 0));
        //{{row, col}, time};
        int time = 0;
        queue<pair<pair<int, int>, int>> que;
        for (int i = 0; i < gridRow; i++) {
            for (int j = 0; j < gridCol; j++) {
                if (grid[i][j] == 2) {
                    que.push({{i, j}, time});
                    visited[i][j] = 2;
                }
                if (grid[i][j] == 1) {
                    ctrFresh++;
                }
            }
        }
        int maxTime = 0;
        //This is the same as FloodFill problem but with a little modification
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        int ctrCheck = 0;
        while (!que.empty()) {
            int curRow = que.front().first.first;
            int curCol = que.front().first.second;
            time = que.front().second;

            maxTime = max(maxTime, time);

            que.pop();
            for (int i = 0; i < 4; i++) {
                int tempRow = curRow + delRow[i];
                int tempCol = curCol + delCol[i];
                if (tempRow >= 0 && tempRow < gridRow && tempCol >= 0 && tempCol < gridCol &&
                    visited[tempRow][tempCol] == 0 && grid[tempRow][tempCol] == 1) {
                    que.push({{tempRow, tempCol}, time + 1});
                    visited[tempRow][tempCol] = 2;
                    ctrCheck++;
                }
            }
        }
        if (ctrCheck != ctrFresh) return -1;

        return maxTime;
    }
};

int main(){
    int gridRow, gridCol;
    cin >> gridRow >> gridCol;
    vector<vector<int>> grid(gridRow, vector<int>(gridCol, 0));
    for (int i = 0; i < gridRow; i++){
        for (int j = 0; j < gridCol; j++){
            cin >> grid[i][j];
        }
    }
    Solution sol;
    cout << sol.orangesRotting(grid) << endl;
    return 0;
}