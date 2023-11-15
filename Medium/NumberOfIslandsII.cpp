#include <bits/stdc++.h>
using namespace std;
/*
Problem name ; Number of Islands II
Problem link : https://practice.geeksforgeeks.org/problems/number-of-islands-ii/1#
Explanation : 
_____________________________________________________________________________________
Part 1 : What we had and what we need to do ?
We've given a matrix and a list of operation to be performed on the matrix.
The operation are the {Row,Col} of the matrix. 
For the given operation we've to mark the cell as islands and check in four direction 
if there is any island present the join them and reduce the count of islands.
_____________________________________________________________________________________
Part 2 : How we'll do it ?
If we observe that at each step we've to create and if required we've to merge the 
islands. So we can think of a algorithm or a data structure which can merge find of they are
already merge or not and if not then merge them.

So we can use the Disjoint Data Structure to solve this problem.
_____________________________________________________________________________________
Part 3 : How we'll solve the problem using Disjoint Data Structure ?
We'll create a disjoint set , visited array , ans and counter variable.
Disjoint set will store the parent node and keeping adding as the numbeer of operation 
keep growing.
Visited array will store the visited node and It'll help us to check if the node is already
visited or node. And while merging the node we'll check if the node is already visited or not
if it's visited means thatt there is an island. 
counter variable will keep track of the number of islands.

Ans store the number of islands at each step.

--------------------------------------------------------------------------------------------

Part 4 : 
Flow of code 
1. Create a disjoint set , visited array , ans and counter variable.
2. Iterate over the operation list.
3. Check if the node is already visited or not.
4. If not then mark it as visited and increase the counter variable.
5. Iterate over the four direction and check if the node is valid or not.
6. If valid then check if the node is visited or not.
7. If visited then check if the node is already connected or not.
8. If not connected then merge them and decrease the counter variable.
9. Push the counter variable in the ans array.
10. Return the ans array.


--------------------------------------------------------------------------------------------

*/
class DisjointDataStructureUsingRank{
    public:
    vector<int> parent;
    vector<int> rank;
    DisjointDataStructureUsingRank(int n){
        parent.resize(n);
        rank.resize(n);
        for(int i = 0 ; i < n ; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int find(int x){
        if(parent[x] == x) return x;
        return (parent[x] = find(parent[x]));
    }
    void union_set(int x,int y){
        int parentOfX = find(x);
        int parentOfY = find(y);
        if(rank[parentOfX] > rank[parentOfY]){
            parent[parentOfY] = parentOfX;
        }
        else{
            parent[parentOfX] = parentOfY;
            if(rank[parentOfX] == rank[parentOfY]){
                rank[parentOfY]++;
            }
        }
    }
    bool isConnected(int x,int y){
        if(find(x) == find(y)) return true;
        return false;
    }
};
class Solution {
  private: 
  bool isValidIdx(int newRow , int newCol , int n ,int m){
      return (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m);
  }
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointDataStructureUsingRank ds(n*m);
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        
        int ctr = 0 ;
        
        vector<int> ans ;
        int deltaRow[] = {-1,0,1,0};
        int deltaCol[] = {0,1,0,-1};
        for(auto it : operators){
            int row = it[0];
            int col = it[1];
            
            if(visited[row][col]){
                ans.push_back( ctr);
                continue;
            }
            
            visited[row][col] = true;
            ctr++;
            
            for(int i = 0 ; i < 4 ;i++){
                int adjRow = row + deltaRow[i];
                int adjCol = col + deltaCol[i];
                
                if(isValidIdx(adjRow,adjCol,n,m)){
                    if(visited[adjRow][adjCol]){
                        int curNodeNum = row * m + col ;
                        int adjNodeNum = adjRow * m + adjCol ; 
                        if(!ds.isConnected(curNodeNum,adjNodeNum)){
                            ctr--;
                            ds.union_set(curNodeNum,adjNodeNum);
                        }
                    }
                }
            }
            ans.push_back( ctr);
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}
