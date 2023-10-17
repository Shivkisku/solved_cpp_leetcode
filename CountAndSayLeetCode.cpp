#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string s = countAndSay(n - 1);
        string res = "";
        for (int i = 0; i < s.size(); i++) {
            int count = 1;
            while (i < s.size() - 1 && s[i] == s[i + 1]) {
                i++;
                count++;
            }
            res.append(to_string(count) + s[i]);
        }
        return res;
    }
};

int main() {
    Solution sol;
    int n = 5;
    string result = sol.countAndSay(n);
    cout << "Output: " << result << endl;
    return 0;
}
