#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        int j = i;
        while (j >= 0 && s[j] != ' ') {
            j--;
        }
        return i - j;
    }
};

int main() {
    // Example string
    string str = "Hello World";

    // Create a solution object
    Solution solution;

    // Call the lengthOfLastWord function
    int length = solution.lengthOfLastWord(str);

    // Print the output
    cout << "Length of the last word is: " << length << endl;

    return 0;
}
