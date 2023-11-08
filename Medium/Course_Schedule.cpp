#include<bits/stdc++.h>
using namespace std;

/*
Problem link : https://leetcode.com/problems/course-schedule/
Problem statement : There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi]
indicates that you must take course bi first if you want to take course ai. For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1. Return true
if you can finish all courses. Otherwise, return false.

Explanation : 
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int m = numCourses;
        int n = prerequisites.size();
        vector<int> adj[numCourses];
        for (int i = 0; i < n; i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        int indeg[m];
        for (int i = 0; i < m; i++) indeg[i] = 0;
        for (int i = 0; i < m; i++) {
            for (auto node : adj[i]) {
                indeg[node]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < m; i++) {
            if (indeg[i] == 0) q.push(i);
        }
        vector<int> topo;
        while (!q.empty()) {
            int frontNode = q.front();
            q.pop();
            topo.push_back(frontNode);
            for (auto node : adj[frontNode]) {
                indeg[node]--;
                if (indeg[node] == 0) q.push(node);
            }
        }

        // Check if a valid topological order exists
        if (topo.size() == m) {
            return true;
        } else {
            return false;
        }
    }
};

int main(){
    Solution s;
    vector<vector<int>> v = {{1,0},{0,1}};
    cout << s.canFinish(2, v) << endl;
    return 0;
}