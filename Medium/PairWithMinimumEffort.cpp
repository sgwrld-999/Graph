#include<bits/stdc++.h>
using namespace std;

/* 
Syntax for priority queue: priority_queue <storingDataType, vector<storingDataType>, greater<storingDataType>> pq;
greater is used to make the priority queue min heap and less is used to make the priority queue max heap.
vector<storingDataType> is used to make the priority queue work with the user defined data types.
greater<storingDataType> is used to make the priority queue work with the user defined data types.

Problem name : Path With Minimum Effort
Problem link : https://leetcode.com/problems/path-with-minimum-effort/
Explanation:
We have to find the minimum effort path from the top left corner to the bottom right corner.
We can move in 4 directions from a cell. And the effort required to move from one cell to another is the maximum of the absolute difference between the heights of the two cells.
or the difference between the values that are stored in the two cells. 

So,we need to go to somewhere to somewhere and also look for the minimum cost then suitable algorithm is Dijkstra's algorithm.

So the approach is similar to the approach of Dijkstra's algorithm.

*/
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        //Always store the differenet variables for row and col if it's not mention that the matrix is square.
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> dist(n, vector<int>(m, 1e9)); //1e9 is 10^9
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        //Delta matrix for   
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int diff = it.first;
            int curC = it.second.second;
            int curR = it.second.first;

            if (curR == n - 1 && curC == m - 1) return diff;

            for (int i = 0; i < 4; i++) {
                int newR = curR + dr[i];
                int newC = curC + dc[i];

                if (newR >= 0 && newR < n && newC >= 0 && newC < m) { 
                    int newEffort = max(abs(heights[newR][newC] - heights[curR][curC]), dist[curR][curC]);
                    if (newEffort < dist[newR][newC]) {
                        dist[newR][newC] = newEffort;
                        pq.push({newEffort, {newR, newC}});
                    }
                }
            }
        }
        return 0;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> heights = {{1,2,2},{3,8,2},{5,3,5}};
    cout << sol.minimumEffortPath(heights) << endl;
    return 0;
}