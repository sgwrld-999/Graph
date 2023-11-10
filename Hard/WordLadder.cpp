#include <bits/stdc++.h>
using namespace std;

/*
Problem link : https://leetcode.com/problems/word-ladder/
Problem statement : Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
                     1. Only one letter can be changed at a time.
                     2. Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
                     3. Return 0 if there is no such transformation sequence.
                     4. All words have the same length.
                     5. All words contain only lowercase alphabetic characters.
                     6. You may assume no duplicates in the word list.
                     7. You may assume beginWord and endWord are non-empty and are not the same.
Brute froce approach : BFS
Explanation of the code : 
We have to replace and check if the word is presetn or not in the wordList.
It'll go like 
hit -> hot -> dot -> dog -> cog

hit -> ait -> bit -> cit ..hit -> .. -> zit // hit is the begin word so we will ignore the hit.
hat -> hbt -> hct -> ..hot.. -> hzt // hot is the next word in wordList so we will increase the stepcount
and try to find the next word.
We look carefully it's forming a  tree like structure so we will use Level order traversal or we can say that we will use BFS.
*/

class Solution1 {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> que;
        que.push({beginWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        
        while (!que.empty()) {
            string currWord = que.front().first;
            int step = que.front().second;
            que.pop();
            
            if (currWord == endWord) return step;
            
            for (int i = 0; i < currWord.size(); ++i) {
                char og = currWord[i];
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    currWord[i] = ch;
                    if (st.find(currWord) != st.end()) {
                        st.erase(currWord);
                        que.push({currWord, step + 1});
                    }
                }
                currWord[i] = og;
            }
        }
        return 0;
    }
};

int main(){
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    Solution1 s;
    cout<<s.ladderLength(beginWord,endWord,wordList);
    return 0;
}
