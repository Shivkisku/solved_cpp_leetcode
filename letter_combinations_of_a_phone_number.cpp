#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size() == 0) return res;
        string s = "";
        unordered_map<char,vector<int>> m({{'2', {'a','b','c'}},
                                          {'3', {'d','e','f'}},
                                          {'4', {'g','h','i'}},
                                          {'5', {'j','k','l'}},
                                          {'6', {'m','n','o'}},
                                          {'7', {'p','q','r','s'}},
                                          {'8', {'t','u','v'}},
                                          {'9', {'w','x','y','z'}}});
        DFS(m, digits, 0, res, s);
        return res;
    }
    
    void DFS(unordered_map<char,vector<int>>& m, string& digits, int l, vector<string>& res, string& s){
        if(l == digits.size()){
            res.push_back(s);
            return;
        }
        for(int i = 0; i < m[digits[l]].size(); i++){
            s.push_back(m[digits[l]][i]);
            DFS(m, digits, l+1, res, s);
            s.pop_back();
        }
        return;
    } 
};

int main() {
    Solution solution;
    string digits = "23"; // Input string
    vector<string> result = solution.letterCombinations(digits); // Call the function

    // Print the output
    cout << "Output: [";
    for (int i = 0; i < result.size(); i++) {
        cout << "\"" << result[i] << "\"";
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
