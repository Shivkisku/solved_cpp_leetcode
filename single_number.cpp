#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(auto& x: nums) res ^= x;
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 1, 2, 1, 2};
    int result = sol.singleNumber(nums);
    cout << "Output: " << result << endl;
    return 0;
}
