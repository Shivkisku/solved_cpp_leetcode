#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m({{'I', 1}, {'X', 10}, {'C', 100}, {'M', 1000}, {'V', 5}, {'L', 50}, {'D', 500}});
        if (s.size() == 0) return 0;
        int sum = m[s[s.size() - 1]];
        for (int i = s.size() - 2; i >= 0; i--) {
            if (m[s[i]] >= m[s[i + 1]]) sum += m[s[i]];
            else sum -= m[s[i]];
        }
        return sum;
    }
};

int main() {
    Solution solution;
    string s = "MCMXCIV"; // Input string
    int result = solution.romanToInt(s); // Call the function

    // Print the output
    cout << "Output: " << result << endl;

    return 0;
}
