#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int distance = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            distance = max(distance, i + nums[i]);
            if (distance == i) return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,3,1,1,4};
    bool result = sol.canJump(nums);
    cout << "Output: " << (result ? "true" : "false") << endl;
    return 0;
}
