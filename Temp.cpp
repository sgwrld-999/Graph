
#include <iostream>
#include <vector>

using namespace std;

pair<int, int> findElement(vector<vector<int>>& A, int k) {
    int n = A.size();
    int i = 0, j = n - 1;
    while (i < n && j >= 0) {
        if (A[i][j] == k) {
            return make_pair(i, j);
        } else if (A[i][j] > k) {
            j--;
        } else {
            i++;
        }
    }
    return make_pair(-1, -1);
}

int main() {
    vector<vector<int>> A = {{1, 4, 7, 11, 15},
                             {2, 5, 8, 12, 19},
                             {3, 6, 9, 16, 22},
                             {10, 13, 14, 17, 24},
                             {18, 21, 23, 26, 30}};
    int k = 5;
    pair<int, int> pos = findElement(A, k);
    if (pos.first == -1 && pos.second == -1) {
        cout << k << " is not present in A." << endl;
    } else {
        cout << "Row: " << pos.first << ", Column: " << pos.second << endl;
    }
    return 0;
}
