#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> v(numRows, "");
        int d = 1;
        int row = 0;
        for (auto c : s) {
            v[row].push_back(c);
            row += d;
            if (row == numRows - 1) d = -1;
            if (row == 0) d = 1;
        }
        string res;
        for (auto x : v) res.append(x);
        return res;
    }
};

int main() {
    Solution solution;
    string inputString = "PAYPALISHIRING"; // Input string
    int numRows = 3; // Number of rows
    string result = solution.convert(inputString, numRows); // Call the function

    // Print the output
    cout << "Output: " << result << endl;

    return 0;
}
