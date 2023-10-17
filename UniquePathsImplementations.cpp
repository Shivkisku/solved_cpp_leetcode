#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; i++) dp[i][0] = 1;
        for (int i = 0; i < n; i++) dp[0][i] = 1;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

class Solution2 {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[1][1] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
};

class Solution3 {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n);
        dp[0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};

int main() {
    // Example inputs for m and n
    int m = 3;
    int n = 3;

    // Create solution objects
    Solution solution;
    Solution2 solution2;
    Solution3 solution3;

    // Call the uniquePaths function for each solution
    int result1 = solution.uniquePaths(m, n);
    int result2 = solution2.uniquePaths(m, n);
    int result3 = solution3.uniquePaths(m, n);

    // Print the output for each solution
    cout << "Solution 1 - Unique Paths: " << result1 << endl;
    cout << "Solution 2 - Unique Paths: " << result2 << endl;
    cout << "Solution 3 - Unique Paths: " << result3 << endl;

    return 0;
}
