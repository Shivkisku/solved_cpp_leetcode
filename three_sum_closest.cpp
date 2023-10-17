#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff = INT_MAX, res = 0;
        for(int i = 0; i < nums.size() - 2; i++){
            int lo = i + 1, hi = nums.size() - 1;
            while(lo < hi){
                int sum = nums[i] + nums[lo] + nums[hi];
                if(sum == target) return target;
                if(abs(sum - target) < diff) diff = abs(sum - target), res = sum;
                (sum > target) ? hi-- : lo++;
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {-1, 2, 1, -4}; // Input vector
    int target = 1; // Target integer
    int result = solution.threeSumClosest(nums, target); // Call the function

    // Print the output
    cout << "Output: " << result << endl;

    return 0;
}
