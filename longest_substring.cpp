#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int maxlen = 0;
        for (int i = 0, j = 0; j < s.size(); j++) {
            m[s[j]]++;
            while (m[s[j]] > 1) {
                m[s[i++]]--;
            }
            maxlen = max(maxlen, j - i + 1);
        }
        return maxlen;
    }
};

int main() {
    Solution solution;
    string inputString = "abcabcbb"; // Input string
    int result = solution.lengthOfLongestSubstring(inputString); // Call the function

    // Print the output
    cout << "Output: " << result << endl;

    return 0;
}
