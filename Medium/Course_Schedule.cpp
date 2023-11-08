#include<bits/stdc++.h>
using namespace std;

/*
Problem link : https://leetcode.com/problems/course-schedule/
Problem statement : There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi]
indicates that you must take course bi first if you want to take course ai. For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1. Return true
if you can finish all courses. Otherwise, return false.

Explanation : The question is similar to the findina a cycle in a directed acylic graph. So we will use the same approach as we used in the finding a cycle in a directed acyclic graph.
We can do by BFS or DFS using the path visited array and visited array.
But If we look carefully there is a dependency of one coursre to another course.
Means if A then B and order should be maintain.
Similar to the topological sort. Where nodes have the dependency on other nodes.
Similar code as the topological sort.  
*/

class Solution1 {
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

//The Course Schedule II
/*
The logic is similar to the above question. Just we need to return the topological order.
But the difference is here that the dependencies are reverserd here.
For example : If A then B. But here it is given that B then A.
Means for taking B course we need first complete the course A first.
*/
class Solution2 {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int m = numCourses;
        int n = prerequisites.size();
        
        vector<int> adj[numCourses];
        for (int i = 0; i < n; i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]); // Only change will be here
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
        
        if (topo.size() == m) {
            return topo;
        } else {
            return {};
        }
    }
};
int main(){
    Solution1 s;
    vector<vector<int>> v = {{1,0},{0,1}};
    cout << s.canFinish(2, v) << endl;
    return 0;
}