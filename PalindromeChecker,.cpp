#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j){
            while(i < j && !isalnum(s[i])) i++;
            while(i < j && !isalnum(s[j])) j--;
            if(tolower(s[i++]) != tolower(s[j--])) return false;
        }
        return true;
    }
};

int main() {
    Solution solution;
    string test1 = "A man, a plan, a canal: Panama";
    string test2 = "race a car";
    
    cout << "Test 1: " << (solution.isPalindrome(test1) ? "True" : "False") << endl;
    cout << "Test 2: " << (solution.isPalindrome(test2) ? "True" : "False") << endl;

    return 0;
}
