#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for (auto s: strs) {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            m[tmp].push_back(s);
        }
        for (auto x: m) res.push_back(x.second);
        return res;
    }
};

class Solution2 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for (auto s: strs) {
            string tmp = s;
            sortStr(tmp);
            m[tmp].push_back(s);
        }
        for (auto x: m) res.push_back(x.second);
        return res;
    }
    
    void sortStr(string& s) {
        unordered_map<char, int> m;
        for (auto c: s) m[c]++;
        string res = "";
        for (int i = 0; i < 26; i++) {
            while (m['a' + i]-- > 0) res.push_back('a' + i);
        }
        s = res;
    }
};

int main() {
    Solution sol1;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto result1 = sol1.groupAnagrams(strs);
    cout << "Output using sort() function: " << endl;
    for (const auto& v : result1) {
        cout << "[";
        for (const auto& str : v) {
            cout << str << " ";
        }
        cout << "]" << endl;
    }

    Solution2 sol2;
    auto result2 = sol2.groupAnagrams(strs);
    cout << "Output using custom sort() function: " << endl;
    for (const auto& v : result2) {
        cout << "[";
        for (const auto& str : v) {
            cout << str << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
