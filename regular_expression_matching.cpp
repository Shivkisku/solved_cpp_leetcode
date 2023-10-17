#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        if(s.empty()) return p.empty() || (p[1] == '*' ? isMatch(s, p.substr(2)) : false);
        if(p[0] != '.' && s[0] != p[0]) return p[1] == '*' ? isMatch(s, p.substr(2)) : false;
        if(p[1] == '*') return isMatch(s.substr(1), p) || isMatch(s, p.substr(2));
        return isMatch(s.substr(1), p.substr(1));
    }
};

int main() {
    Solution solution;
    string s = "aa"; // Input string s
    string p = "a"; // Input string p
    bool result = solution.isMatch(s, p); // Call the function

    // Print the output
    cout << "Output: " << (result ? "true" : "false") << endl;

    return 0;
}
