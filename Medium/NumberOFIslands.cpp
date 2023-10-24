#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    //Simple BFS on a 2D grid but the only difference is that we have to keep track of the visited nodes via a visited matrix
    //Time complexity : O(row * col)
    void BFS(int row,int col,vector<vector<char>>& grid,vector<vector<bool>>& visited, int nodeRow , int nodeCol){
        queue<pair<int,int>> q;
        q.push({nodeRow,nodeCol});
        visited[nodeRow][nodeCol] = true ;
        while(!q.empty()){
            int rowFNode = q.front().first;
            int colFNode = q.front().second;
            q.pop();
            if(rowFNode-1 >= 0){
                if(grid[rowFNode-1][colFNode] == '1'){
                    if(!visited[rowFNode-1][colFNode]){
                        q.push({rowFNode-1,colFNode}); 
                        visited[rowFNode-1][colFNode] = true ;
                    }
                }
            }
            if(rowFNode+1 < row){
                if(grid[rowFNode+1][colFNode] == '1'){
                    if(!visited[rowFNode+1][colFNode]){
                        q.push({rowFNode+1,colFNode}); 
                        visited[rowFNode+1][colFNode] = true ;
                    }
                }
            }
            if(colFNode - 1 >= 0){
                if(grid[rowFNode][colFNode-1] == '1'){
                    if(!visited[rowFNode][colFNode-1]){
                        q.push({rowFNode,colFNode-1}); 
                        visited[rowFNode][colFNode-1] = true ;
                    }
                }
            }
            if(colFNode+1 < col){
                if(grid[rowFNode][colFNode+1] == '1'){
                    if(!visited[rowFNode][colFNode+1]){
                        q.push({rowFNode,colFNode+1}); 
                        visited[rowFNode][colFNode+1] = true ;
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> visited(row,vector<bool>(col,false));
        int ctr = 0 ;
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    ctr++;
                    BFS(row,col,grid,visited,i,j);
                }
            }
        }
        return ctr;
    }
};
/**
 * The main function creates an object of the Solution class and calls the numIslands function
 * to find the number of islands in the given grid. The grid is a 2D vector of characters where
 * '1' represents land and '0' represents water. The function uses depth-first search (DFS) to
 * traverse the grid and count the number of islands.
 */
int main(){
    Solution obj;
    vector<vector<char>> grid = {{'1','1','0','0','0'},
                                 {'1','1','0','0','0'},
                                 {'0','0','1','0','0'},
                                 {'0','0','0','1','1'}};
    cout << obj.numIslands(grid) << endl;
}