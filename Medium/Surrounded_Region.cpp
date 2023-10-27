
#include<bits/stdc++.h>
using namespace std;
/*
Problem Statement : 
    Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.
    A region is captured by flipping all 'O's into 'X's in that surrounded region.
Explnation : 
Lets understand with an example : 
    Input: board = [["X","X","X","X"],
                    ["X","O","O","X"],
                    ["X","X","O","X"],
                    ["X","O","X","X"]]
    Output: [["X","X","X","X"],
            ["X","X","X","X"],
            ["X","X","X","X"],
            ["X","O","X","X"]]
    Explanation: Surrounded regions should not be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. 
    Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. 
    Two cells are connected if they are adjacent cells connected horizontally or vertically.
    Basically agar koi 'O' border pe hai toh usko 'X' mei convert nhi kar payge kyuki ek side se X nhi hai.
    Tu uss 'O' ko DFS se call karenge aur uske saare connected 'O' ko bhi nhi kar payge kyuki ek side se X nhi hai.
    Isliye pehele pata kar lete  h ki koi 'O' border pe hai ya nhi agar hai toh usko aur uske saare connected 'O' ko visited mark kar dete hai.
    Baad mei jo 'O' bacha hai unko 'X' mei convert kar dete hai.
Approach :
    1. We will use DFS to solve this problem.
    2. We will traverse the matrix and if we find 'O' at the border of the matrix then we will call DFS on that cell.
    3. In DFS we will mark the cell as visited and then we will check for all the 4 directions and if we find 'O' then we will call DFS on that cell.
    4. After DFS we will traverse the matrix and if we find 'O' then we will change it to 'X' and if we find 'X' then we will change it to 'O'.
    5. Time Complexity : O(N*M)
    6. Space Complexity : O(N*M)
*/
class Solution {
public:
    int delRow[4] = {-1, 0, 1, 0};
    int delCol[4] = {0, 1, 0, -1};

    void DFS(int i, int j, vector<vector<char>>& board, vector<vector<int>>& visited) {
        visited[i][j] = 1;
        int rowOfBoard = board.size();
        int colOfBoard = board[0].size();
        for (int k = 0; k < 4; k++) {
            int tempRow = i + delRow[k];
            int tempCol = j + delCol[k];
            if (tempRow >= 0 && tempRow < rowOfBoard && tempCol >= 0 && tempCol < colOfBoard && !visited[tempRow][tempCol] && board[tempRow][tempCol] == 'O') {
                DFS(tempRow, tempCol, board, visited);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int rowOfBoard = board.size();
        if (rowOfBoard == 0) return;  
        int colOfBoard = board[0].size();
        if (colOfBoard == 0) return; 

        vector<vector<int>> visited(rowOfBoard, vector<int>(colOfBoard, 0));

        for (int i = 0; i < rowOfBoard; i++) {
            if (!visited[i][0] && board[i][0] == 'O') {
                DFS(i, 0, board, visited);
            }
            if (!visited[i][colOfBoard - 1] && board[i][colOfBoard - 1] == 'O') {
                DFS(i, colOfBoard - 1, board, visited);
            }
        }

        for (int i = 0; i < colOfBoard; i++) {
            if (!visited[0][i] && board[0][i] == 'O') {
                DFS(0, i, board, visited);
            }
            if (!visited[rowOfBoard - 1][i] && board[rowOfBoard - 1][i] == 'O') {
                DFS(rowOfBoard - 1, i, board, visited);
            }
        }

        for (int i = 0; i < rowOfBoard; i++) {
            for (int j = 0; j < colOfBoard; j++) {
                if (!visited[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

int main(){
    Solution obj;
    vector<vector<char>> board = {{'X', 'X', 'X', 'X'},
                                  {'X', 'O', 'O', 'X'},
                                  {'X', 'X', 'O', 'X'},
                                  {'X', 'O', 'X', 'X'}};
    obj.solve(board);
    for (auto row : board) {
        for (auto col : row) {
            cout << col << " ";
        }
        cout << endl;
    }
    return 0;
}