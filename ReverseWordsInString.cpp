#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Reverse words in-place.
    void reverseWords(string &s) {
        // Reverse string
        reverse(s.begin(), s.end());
        // Reverse every word
        int i = 0, j = 0;
        while (i != s.size()) {
            while (j < s.size() && s[j] != ' ') j++;
            reverse(s.begin() + i, s.begin() + j);
            i = j;
            while (i < s.size() && s[i] == ' ') i++, j++;
        }
        // Remove extra ' '
        i = 0, j = 0;
        while (j < s.size()) {
            bool new_word = false;
            while (j < s.size() && s[j] == ' ') {
                new_word = true;
                j++;
            }
            if (j == s.size()) break;
            if (new_word && i > 0) s[i++] = ' ';
            s[i++] = s[j++];
        }
        s = s.substr(0, i);
    }

    // Reverse words in-place (alternative implementation).
    void reverseWords2(string &s) {
        string res = "";
        string word = "";
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            while (s[i] == ' ') i++;
            j = i;
            while (s[j] != ' ') j++;
            word = s.substr(i, j - i);
            if (res != "" && word != "") word += " ";
            res = word + res;
            i = j;
        }
        s = res;
    }

    // Reverse words in the string (O(1) space).
    void reverseWordsInString(string &s) {
        reverseWords(s);
        cout << "Reversed Words (O(1) space): " << s << endl;
    }

    // Reverse words in the string (O(n) space).
    void reverseWordsInString2(string &s) {
        reverseWords2(s);
        cout << "Reversed Words (O(n) space): " << s << endl;
    }
};

int main() {
    Solution sol;
    string input = "the sky is blue";

    // Test O(1) space implementation
    sol.reverseWordsInString(input);

    // Test O(n) space implementation
    sol.reverseWordsInString2(input);

    return 0;
}
