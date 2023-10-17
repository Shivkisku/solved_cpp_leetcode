#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
private:
    unordered_map<string, int> m;
    unordered_map<string, bool> dp;

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for (auto x : wordDict) m[x]++;
        return DFS(s);
    }

    bool DFS(string s) {
        if (dp.count(s)) return dp[s];
        if (s.empty()) return true;
        bool found = false;
        for (int i = 1; i <= s.size() && !found; i++)
            if (m.count(s.substr(0, i))) found |= DFS(s.substr(i));
        dp[s] = found;
        return found;
    }
};

int main() {
    Solution sol;
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    bool result = sol.wordBreak(s, wordDict);
    cout << "Output: " << (result ? "true" : "false") << endl;
    return 0;
}
