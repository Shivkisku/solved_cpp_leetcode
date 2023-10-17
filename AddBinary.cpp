#include <iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        string s = "";
        while (i >= 0 || j >= 0 || carry) {
            int sum = (i < 0 ? 0 : a[i--] - '0') + (j < 0 ? 0 : b[j--] - '0') + carry;
            s = to_string(sum % 2) + s;
            carry = sum / 2;
        }
        return s;
    }
};

int main() {
    // Example binary strings
    string a = "1010";
    string b = "1011";

    // Create a solution object
    Solution solution;

    // Call the addBinary function
    string result = solution.addBinary(a, b);

    // Print the output
    cout << "Result: " << result << endl;

    return 0;
}
