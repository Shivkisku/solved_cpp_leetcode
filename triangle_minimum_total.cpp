#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // Bottom-up
        int n = triangle.size();
        vector<int> dp(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        }
        return dp[0];
    }
};

// Helper function to print the output
void printOutput(int result) {
    cout << "Minimum total: " << result << endl;
}

int main() {
    // Test your inputs here
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};

    Solution sol;
    int result = sol.minimumTotal(triangle);

    // Print the output
    printOutput(result);

    return 0;
}
