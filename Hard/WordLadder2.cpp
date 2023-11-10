#include<bits/stdc++.h>
using namespace std;

/*
Problem link : https://leetcode.com/problems/word-ladder-ii/
*/
/*
Exaplanation : 
In this one we have to store the path also. So we will use BFS and store the path in the queue.
But the key thing is here that we'll check from the last element in the list and also we'll not  eliminate frome the 
set, until we have reached the next level. Means If we have already found that element and store the path then we'll check 
if it's posiible or not in the next path as given in the main function.

*/
class Solution1 {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<vector<string>> que;
        que.push({beginWord});
        unordered_set<string> st(wordList.begin(), wordList.end());
        vector<string> used;
        used.push_back(beginWord);
        int level = 0;
        vector<vector<string>> ans;

        while (!que.empty()) {
            vector<string> frontList = que.front();
            que.pop();

            if (frontList.size() > level) {
                level++;
                for (auto& i : used) {
                    st.erase(i);
                }
            }

            string lastWord = frontList.back();
            if (lastWord == endWord) {
                if (ans.size() == 0) {
                    ans.push_back(frontList);
                } else if (frontList.size() == ans[0].size()) {
                    ans.push_back(frontList);
                }
            }

            for (int i = 0; i < lastWord.size(); ++i) {
                char og = lastWord[i];
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    lastWord[i] = ch;
                    if (st.count(lastWord) > 0) {
                        vector<string> newFrontList = frontList;
                        newFrontList.push_back(lastWord);
                        que.push(newFrontList);
                        used.push_back(lastWord);
                    }
                }
                lastWord[i] = og;
            }
        }

        return ans;
    }
};

int main(){
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    Solution1 s;
    vector<vector<string>> ans = s.findLadders(beginWord, endWord, wordList);
    for (auto& i : ans) {
        for (auto& j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}