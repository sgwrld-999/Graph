#include<bits/stdc++.h>
using namespace std;
/*
Problem link : https://leetcode.com/problems/flood-fill/
Constraints:
    m == image.length
    n == image[i].length
    1 <= m, n <= 50
    0 <= image[i][j], newColor < 216
    0 <= sr < m
    0 <= sc < n
Problem logic : 
    We've have to change the color of the pixel at the given position and all the adjacent pixels of the same color as well as the 
    changed or nieghbours of the source cell.So,the best algorithm is the BFS or DFS.
    But we'll do the BFS because we don't have to go to the depth of the graph.
*/

class Solution {
public:
    void BFS(vector<vector<int>>& image, vector<vector<bool>>& visited, int sr, int sc, int color) {
        long long rowOfImage = image.size();
        long long colOfImage = image[0].size();
        queue<pair<int, int>> q;
        q.push({sr, sc});
        visited[sr][sc] = true;
        int initalColor = image[sr][sc];
        image[sr][sc] = color;

        while (!q.empty()) {
            int rowFrontEle = q.front().first;
            int colFrontEle = q.front().second;
            q.pop();

            // if (rowFrontEle - 1 >= 0) {
            //     if (!visited[rowFrontEle - 1][colFrontEle]) {
            //         if (image[rowFrontEle - 1][colFrontEle] == initalColor) {
            //             q.push({rowFrontEle - 1, colFrontEle});
            //             visited[rowFrontEle - 1][colFrontEle] = true;
            //             image[rowFrontEle - 1][colFrontEle] = color;
            //         }
            //     }
            // }

            // if (rowFrontEle + 1 < rowOfImage) {
            //     if (!visited[rowFrontEle + 1][colFrontEle]) {
            //         if (image[rowFrontEle + 1][colFrontEle] == initalColor) {
            //             q.push({rowFrontEle + 1, colFrontEle});
            //             visited[rowFrontEle + 1][colFrontEle] = true;
            //             image[rowFrontEle + 1][colFrontEle] = color;
            //         }
            //     }
            // }

            // if (colFrontEle - 1 >= 0) {
            //     if (!visited[rowFrontEle][colFrontEle - 1]) {
            //         if (image[rowFrontEle][colFrontEle - 1] == initalColor) {
            //             q.push({rowFrontEle, colFrontEle - 1});
            //             visited[rowFrontEle][colFrontEle - 1] = true;
            //             image[rowFrontEle][colFrontEle - 1] = color;
            //         }
            //     }
            // }

            // if (colFrontEle + 1 < colOfImage) {
            //     if (!visited[rowFrontEle][colFrontEle + 1]) {
            //         if (image[rowFrontEle][colFrontEle + 1] == initalColor) {
            //             q.push({rowFrontEle, colFrontEle + 1});
            //             visited[rowFrontEle][colFrontEle + 1] = true;
            //             image[rowFrontEle][colFrontEle + 1] = color;
            //         }
            //     }
            // }
            //The above and the below code is same but the below code is same but instead of the manually check we are 
            // doing using the same loop.
            int deltaRow[] = {-1, 1, 0, 0};
            int deltaCol[] = {0, 0, -1, 1};
            for (int i = 0; i < 4; i++) {
                int newRow = rowFrontEle + deltaRow[i];
                int newCol = colFrontEle + deltaCol[i];
                if (newRow >= 0 && newRow < rowOfImage && newCol >= 0 && newCol < colOfImage) {
                    if (!visited[newRow][newCol]) {
                        if (image[newRow][newCol] == initalColor) {
                            q.push({newRow, newCol});
                            visited[newRow][newCol] = true;
                            image[newRow][newCol] = color;
                        }
                    }
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        long long rowOfImage = image.size();
        long long colOfImage = image[0].size();
        vector<vector<bool>> visited(rowOfImage, vector<bool>(colOfImage, false));
        BFS(image, visited, sr, sc, color);
        return image;
    }
};
class Solution1 {
public:
    void DFS(vector<vector<int>>& image, vector<vector<bool>>& visited, int row, int col, int newColor, int originalColor) {
        if (row < 0 || row >= image.size() || col < 0 || col >= image[0].size() || visited[row][col] || image[row][col] != originalColor) {
            return;
        }
        visited[row][col] = true;
        image[row][col] = newColor;
        DFS(image, visited, row - 1, col, newColor, originalColor); 
        DFS(image, visited, row + 1, col, newColor, originalColor);
        DFS(image, visited, row, col - 1, newColor, originalColor);
        DFS(image, visited, row, col + 1, newColor, originalColor); 
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int originalColor = image[sr][sc];
        if (originalColor == newColor) {
            return image;
        }
        int rowOfImage = image.size();
        int colOfImage = image[0].size();
        vector<vector<bool>> visited(rowOfImage, vector<bool>(colOfImage, false));
        DFS(image, visited, sr, sc, newColor, originalColor);
        return image;
    }
};

int main() {
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1, sc = 1, newColor = 2;

    Solution sol;
    vector<vector<int>> result = sol.floodFill(image, sr, sc, newColor);

    // Print the result
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[0].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
