#include<bits/stdc++.h>
using namespace std;
/*
Problem name : Cheapest Flights Within K Stops
Problem link : https://leetcode.com/problems/cheapest-flights-within-k-stops/
Explanation:
We have to find the cheapest flight from the source to the destination with at most k stops.
If look or observe carefully it's a graph problem and also in which we have to find the shortest path with positive weights of the edges.
So, the suitable algorithm is Dijkstra's algorithm. But the catch here is that we have to reach the destination with at most k stops.
Means the priority will be given to the number of stops rather than the cost of the path.
If we calculate giving the path cost the priority then we will get the wrong answer.

It'll be similar to the approach of Dijkstra's algorithm but we'll update value when the number of stops is less than or equal to k and the cost of the path is less than the previous cost of the path.
*/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adjList[n];
        for( const auto node : flights){
            adjList[node[0]].push_back({node[1],node[2]});
        }
        
        queue<pair<int,pair<int,int>>> que; // Required queue {steps,{node,cost}}

        que.push({0,{src,0}});

        vector<int> dist(n,1e9);// 1e9 is 10^9

        while(!que.empty()){
            auto it = que.front(); 
            que.pop();

            int steps = it.first;
            int currNode = it.second.first ;
            int currCost = it.second.second ;
            
            if(steps > k ) continue; // If steps is greater than k then we don't need to go further.

            for(auto node : adjList[currNode]){
                int newNode = node.first  ;
                int newCost = node.second ;

                if(steps <= k && newCost + currCost < dist[newNode]){
                   dist[newNode] = newCost + currCost ;
                   que.push({steps+1,{newNode, newCost + currCost }});
                }
            }
        }
        return (dist[dst] == 1e9) ? -1 : dist[dst];
    }
};

int main(){
    Solution sol;
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{0,2,500}};
    cout << sol.findCheapestPrice(3,flights,0,2,1) << endl;
    return 0;
}