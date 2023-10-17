#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        unordered_map<char, int> m;
        for (auto x : needle) m[x]++;
        int count = needle.size();
        int begin = 0, end = 0;
        while (end < haystack.size()) {
            if (m[haystack[end++]]-- > 0) count--;
            if (count == 0) {
                int i = begin, j = 0;
                while (j < needle.size() && haystack[i] == needle[j]) i++, j++;
                if (j == needle.size()) return begin;
            }
            if (end - begin == needle.size() && m[haystack[begin++]]++ >= 0) count++;
        }
        return -1;
    }
};

int main() {
    Solution sol;
    string haystack = "mississippi";
    string needle = "pi";
    int result = sol.strStr(haystack, needle);
    cout << "Output: " << result << endl;
    return 0;
}
