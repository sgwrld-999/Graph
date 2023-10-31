#include<bits/stdc++.h>
using namespace std;
/*
Problem Statement: https://leetcode.com/problems/01-matrix/
Solution: BFS
Explanation : We've to find the nearest 0 from the each cell(1).
We can trasverse the matrix and find the nearest 0 from each cell(1) but it will take O(n^2) time.
The time complexity of the code is O(n*m) and space complexity is O(n*m).Because we are iterating from each cell which is not 0.
For example : 
    0 1 1 
    1 1 1
    1 1 1 
    Here for the (2,2) we have to iterate over all the cells to find the nearest 0.
    And the resultant matrix will be :
    0 1 2
    1 2 3
    2 3 4

    But we can do better than this.But the question is how?
    Since the distance between 0 and 1 will be same as the distance between 1 and 0.
    So we can start from the 0 and find the nearest 1 from it and then we can find the nearest 1 from the 1 and so on and increnent the distance by one as well as marked them visited.
    We can use BFS to find the nearest 1 from the 0.
    This time we don't have to iterate over all the cells.As we are starting from the 0 and we are finding the nearest 1 from it.
    And then we are finding the nearest 1 from the 1 and so on.
    So,it's kind of like a BFS of O(n*m) time complexity.
    
    */
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rowOfMat = mat.size();
        int colOfMat = mat[0].size();

        vector<vector<int>> distance(rowOfMat, vector<int>(colOfMat, -1));
        queue<pair<int, int>> que;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for (int i = 0; i < rowOfMat; i++) {
            for (int j = 0; j < colOfMat; j++) {
                if (mat[i][j] == 0) { 
                    distance[i][j] = 0;
                    que.push({i, j});
                }
            }
        }
        while (!que.empty()) {
            int frontRow = que.front().first;
            int frontCol = que.front().second;
            que.pop();
            for (int k = 0; k < 4; k++) {
                int tempRow = frontRow + delRow[k];
                int tempCol = frontCol + delCol[k];
                if (tempRow < rowOfMat && tempCol < colOfMat && tempRow >= 0 && tempCol >= 0 && distance[tempRow][tempCol] == -1) {
                    distance[tempRow][tempCol] = 1 + distance[frontRow][frontCol];
                    que.push({tempRow, tempCol});
                }
            }
        }

        return distance; 
    }
};

int main(){
    int rowOfMat,colOfMat;
    cin>>rowOfMat>>colOfMat;
    vector<vector<int>> mat(rowOfMat,vector<int>(colOfMat,0));
    for(int i=0;i<rowOfMat;i++){
        for(int j=0;j<colOfMat;j++){
            cin>>mat[i][j];
        }
    }
    Solution obj;
    vector<vector<int>> ans = obj.updateMatrix(mat);
    for(int i=0;i<rowOfMat;i++){
        for(int j=0;j<colOfMat;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}