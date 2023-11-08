//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    string findOrder(string dict[], int N, int K) {
        // Creating the adjacency list
        vector<int> adj[K];
        for (int i = 0; i < N - 1; i++) { // N - 1 because we are comparing with a pair
            string s1 = dict[i];
            string s2 = dict[i + 1];
            int shortestLen = min(s1.size(), s2.size());
            for (int j = 0; j < shortestLen; j++) {
                if (s1[j] != s2[j]) {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }

        // Topological sort
        int inDeg[K];
        for (int i = 0; i < K; i++) inDeg[i] = 0;
        for (int i = 0; i < K; i++) {
            for (const auto it : adj[i]) {
                inDeg[it]++;
            }
        }

        vector<int> topoSort;
        queue<int> que;

        for (int i = 0; i < K; i++) {
            if (inDeg[i] == 0) que.push(i);
        }

        while (!que.empty()) {
            int frontNode = que.front();
            que.pop();
            topoSort.push_back(frontNode);
            for (auto node : adj[frontNode]) {
                inDeg[node]--;
                if (inDeg[node] == 0) que.push(node);
            }
        }

        string ans = "";
        for (auto s : topoSort) {
            ans += (char)(s + 'a');
        }

        return ans;
    }
};


//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends