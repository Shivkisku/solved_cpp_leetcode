#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string path = "";
        DFS(res, n, 0, 0, path);
        return res;
    }
    
    void DFS(vector<string>& res, int n, int k, int left, string& path){
        if(left > n) return;
        if(k == n){
            if(left == 0) res.push_back(path);
            return;
        }
        path.push_back('(');
        DFS(res, n, k, left + 1, path);
        path.pop_back();
        
        if(left != 0){
            path.push_back(')');
            DFS(res, n, k + 1, left - 1, path);
            path.pop_back();
        }
    }
};

// Function to print the output
void printOutput(const vector<string>& result) {
    cout << "Output: [";
    for (int i = 0; i < result.size(); i++) {
        cout << "\"" << result[i] << "\"";
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;
    int n = 3; // Example value of n
    vector<string> result = solution.generateParenthesis(n); // Call the function

    // Print the output
    printOutput(result);

    return 0;
}
