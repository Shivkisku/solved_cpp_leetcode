#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> dp(n);
        dp[0] = obstacleGrid[0][0] == 0 ? 1 : 0; // If the starting cell is not an obstacle, there is one way to reach it.
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0; // If the current cell is an obstacle, set the number of ways to 0.
                } else if (j > 0) {
                    dp[j] += dp[j - 1]; // If the current cell is not an obstacle and not in the first column, add the number of ways from the left cell.
                }
            }
        }
        return dp[n - 1];
    }
};

int main() {
    // Example obstacle grid
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};

    // Create a solution object
    Solution solution;

    // Call the uniquePathsWithObstacles function
    int result = solution.uniquePathsWithObstacles(obstacleGrid);

    // Print the output
    cout << "Number of Unique Paths: " << result << endl;

    return 0;
}
