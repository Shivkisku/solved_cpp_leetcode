#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string res, s;
        stack<string> stk;
        stringstream ss(path);
        while (getline(ss, s, '/')) {
            if (s == "" || s == ".")
                continue;
            if (s == ".." && !stk.empty())
                stk.pop();
            else if (s != "..")
                stk.push(s);
        }
        while (!stk.empty()) {
            res = "/" + stk.top() + res;
            stk.pop();
        }
        return res.empty() ? "/" : res;
    }
};

int main() {
    // Example input
    string path = "/a//b////c/d//././/..";

    // Create a solution object
    Solution solution;

    // Call the simplifyPath function
    string result = solution.simplifyPath(path);

    // Print the output
    cout << "Simplified Path: " << result << endl;

    return 0;
}
