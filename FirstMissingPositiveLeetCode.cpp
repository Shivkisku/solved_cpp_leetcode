#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 1;
        for (int x : nums) if (x == i) i++;
        return i;
    }
};

class Solution2 {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.empty()) return 1;
        for (int i = 0; i < nums.size(); i++)
            while (nums[i] > 0 && nums[i] < nums.size() && nums[i] != nums[nums[i] - 1]) swap(nums[i], nums[nums[i] - 1]);
        for (int i = 0; i < nums.size(); i++) if (nums[i] != i + 1) return i + 1;
        return nums.size() + 1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 4, -1, 1};
    int result1 = sol.firstMissingPositive(nums);
    cout << "Output using O(nlogn) approach: " << result1 << endl;

    Solution2 sol2;
    int result2 = sol2.firstMissingPositive(nums);
    cout << "Output using O(n) approach: " << result2 << endl;
    return 0;
}
