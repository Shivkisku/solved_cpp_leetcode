#include <iostream>
#include <string>

using namespace std;

// My TLE recursion
class Solution1 {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        if (s.empty()) return p.empty() || p[0] == '*' ? isMatch(s, p.substr(1)) : false;
        if (p[0] != '?' && p[0] != '*' && p[0] != s[0]) return false;
        if (p[0] == '*') {
            for (int i = 0; i <= s.size(); i++)
                if (isMatch(s.substr(i), p.substr(1))) return true;
            return false;
        }
        return isMatch(s.substr(1), p.substr(1));
    }
};

// An O(n) solution based on a post
class Solution2 {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0, ss = 0, star = -1;
        while (i < s.size()) {
            if (j < p.size() && (p[j] == '?' || s[i] == p[j])) {
                i++;
                j++;
            } else if (j < p.size() && p[j] == '*') {
                star = j;
                ss = i;
                j++;
            } else if (star != -1) {
                j = star + 1;
                i = ++ss;
            } else
                return false;
        }
        while (j < p.size() && p[j] == '*') j++;
        return j == p.size();
    }
};

int main() {
    Solution1 sol1;
    string s1 = "adceb";
    string p1 = "*a*b";
    bool result1 = sol1.isMatch(s1, p1);
    cout << "Output using TLE recursion: " << (result1 ? "true" : "false") << endl;

    Solution2 sol2;
    string s2 = "adceb";
    string p2 = "*a*b";
    bool result2 = sol2.isMatch(s2, p2);
    cout << "Output using linear runtime solution: " << (result2 ? "true" : "false") << endl;

    return 0;
}
