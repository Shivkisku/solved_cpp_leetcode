#include <iostream>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        int base = 1;
        int i = s[0] == '-' ? 1 : 0;
        int res = 0;
        while (i < s.size()) {
            if (base == 1000000000 && (s[i] - '0' > 2 || INT_MAX - (s[i] - '0') * base < res)) return 0;
            res += (s[i] - '0') * base;
            base *= 10;
            i++;
        }
        return s[0] == '-' ? -res : res;
    }
};

int main() {
    Solution solution;
    int x = 123; // Input integer
    int result = solution.reverse(x); // Call the function

    // Print the output
    cout << "Output: " << result << endl;

    return 0;
}
