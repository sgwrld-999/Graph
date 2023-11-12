//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/*
Problem name : Minimum Multiplications to reach the end
Problem link : https://practice.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/0/#
Explanation:
If we observe it's forming a tree and we have to find the minimum number of steps to reach the end or the destination.
So, the suitable algorithm is Dijkstra's algorithm. 
As we've to reach somehere with minimum steps and also the number of steps is not fixed also wights are positive.
So, we'll use Dijkstra's algorithm.
*/

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        //For an edge case
        if(start == end) return 0; // If start and end are same then we don't need to do any multiplication.
        //It was given that the answer should be return  with mod 10^5 which was the main 
        //catch in this question. that the nodes are in the range of 0 to 10^5 - 1.
        int mod = 100000;
        
        vector<int> steps(100000, 1e9);
        
        steps[start] = 0 ;
        
        queue<pair<int, int>> que; //{steps, node(Number)}
        
        que.push({0, start});

        while (!que.empty()) {
            
            auto it = que.front();
            que.pop();

            int currStep = it.first;
            int currNode = it.second;

            for (auto node : arr) {
                
                int currNum = (currNode * node) % mod;
                
                if (currStep + 1 < steps[currNum]) {
                    
                    steps[currNum] = currStep + 1;

                    if (currNum == end)return currStep + 1;

                    que.push({currStep + 1, currNum});
                    
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends