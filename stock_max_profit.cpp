#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        vector<int> buy(prices.size());
        vector<int> dp(prices.size());
        buy[0] = prices[0];
        dp[0] = 0;
        for (int i = 1; i < prices.size(); i++) {
            buy[i] = min(buy[i - 1], prices[i]);
            dp[i] = max(dp[i - 1], prices[i] - buy[i - 1]);
        }
        return dp[prices.size() - 1];
    }
};

// Helper function to print the output
void printOutput(int result) {
    cout << "Max Profit: " << result << endl;
}

int main() {
    // Test your inputs here
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    Solution sol;
    int result = sol.maxProfit(prices);

    // Print the output
    printOutput(result);

    return 0;
}
