#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        string res = "";
        for (int i = num2.size() - 1, zero = 0; i >= 0; i--, zero++)
            res = addStr(res, multiStr(num1, num2[i] - '0', zero));
        return res;
    }
    // string * multiple -> string
    string multiStr(string s, int multiple, int zero) {
        int carry = 0;
        int n = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            n = (s[i] - '0') * multiple + carry;
            s[i] = n % 10 + '0';
            carry = n / 10;
        }
        if (carry) s = to_string(carry) + s;
        while (zero) s += "0", zero--;
        return s;
    }
    // string + string -> string
    string addStr(string num1, string num2) {
        string s = "";
        int carry = 0;
        for (int i = num1.size() - 1, j = num2.size() - 1; i >= 0 || j >= 0 || carry; i--, j--) {
            int x = i < 0 ? 0 : num1[i] - '0';
            int y = j < 0 ? 0 : num2[j] - '0';
            s.push_back((x + y + carry) % 10 + '0');
            carry = (x + y + carry) / 10;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};

int main() {
    Solution sol;
    string num1 = "123";
    string num2 = "456";
    string result = sol.multiply(num1, num2);
    cout << "Output: " << result << endl;
    return 0;
}
