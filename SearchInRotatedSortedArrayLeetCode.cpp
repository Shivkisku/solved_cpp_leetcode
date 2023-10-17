#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;
        int lo = 0, hi = n - 1;
        int mid = (lo + hi) / 2;
        while (lo < hi) {
            if (nums[mid] > nums[hi]) lo = mid + 1;
            else hi = mid;
            mid = (lo + hi) / 2;
        }
        int pos = (target >= nums[0] && lo != 0) ? lower_bound(nums.begin(), nums.begin() + lo, target) - nums.begin()
                                                 : lower_bound(nums.begin() + lo, nums.end(), target) - nums.begin();
        return nums[pos] == target ? pos : -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int result = sol.search(nums, target);
    cout << "Output: " << result << endl;
    return 0;
}
