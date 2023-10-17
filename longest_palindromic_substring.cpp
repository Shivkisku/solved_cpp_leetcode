#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 0 || s.size() == 1) return s;
        string res;
        int maxlen = 0;
        for (int i = 0; i < s.size() - maxlen; i++) {
            for (int j = s.size() - 1; j >= i + maxlen; j--) {
                if (s[j] != s[i]) continue;
                string str = s.substr(i, j - i + 1);
                if (isPalindrome(str) && str.size() > maxlen) {
                    maxlen = str.size();
                    res = str;
                }
            }
        }
        return res;
    }

    bool isPalindrome(string s) {
        if (s.size() == 0 || s.size() == 1) return true;
        int i(0), j(s.size() - 1);
        while (s[i] == s[j] && i < j) i++, j--;
        return i >= j;
    }
};

int main() {
    Solution solution;
    string inputString = "babad"; // Input string
    string result = solution.longestPalindrome(inputString); // Call the function

    // Print the output
    cout << "Output: " << result << endl;

    return 0;
}
