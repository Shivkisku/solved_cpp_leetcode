#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (auto c : s) {
            if (stk.empty() && (c == ')' || c == ']' || c == '}')) return false;
            if (c == '(' || c == '[' || c == '{') stk.push(c);
            else {
                char left = stk.top();
                if ((c == ')' && left != '(') || (c == ']' && left != '[') || (c == '}' && left != '{')) return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};

int main() {
    Solution solution;
    string input = "{[]()}"; // Example input string
    bool result = solution.isValid(input); // Call the function

    // Print the output
    cout << boolalpha << "Output: " << result << endl;

    return 0;
}
