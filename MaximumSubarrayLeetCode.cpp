#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // dp[i] = max(dp[i - 1] + A[i], A[i])
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int maxSum = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            maxSum = max(maxSum, dp[i]);
        }
        return maxSum;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int result = sol.maxSubArray(nums);
    cout << "Output: " << result << endl;
    return 0;
}
