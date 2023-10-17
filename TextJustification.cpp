#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        if (maxWidth == 0) {
            return {""};
        }
        int i = 0, j = 0;
        while (j != words.size()) {
            int len = -1;
            while (j < words.size() && len + words[j].size() + 1 <= maxWidth) {
                len += words[j].size() + 1;
                j++;
            }
            int space = maxWidth - len + j - i - 1;
            int k = i;
            while (space) {
                words[k++] += " ";
                space--;
                if (j != words.size() && (k == j - 1 || k == j)) {
                    k = i;
                }
                if (j == words.size() && k == j) {
                    k = j - 1;
                }
            }
            string line = "";
            for (int l = i; l < j; l++) {
                line += words[l];
            }
            res.push_back(line);
            i = j;
        }
        return res;
    }
};

// Function to print the vector
void printVector(vector<string>& vec) {
    cout << "Output:" << endl;
    for (string str : vec) {
        cout << str << endl;
    }
}

int main() {
    // Example input
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;

    // Create a solution object
    Solution solution;

    // Call the fullJustify function
    vector<string> result = solution.fullJustify(words, maxWidth);

    // Print the output
    printVector(result);

    return 0;
}
