#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < (int)nums.size() - 1; i++){
            if(i > 0 && nums[i - 1] == nums[i]) continue;
            int lo = i + 1;
            for(int hi = nums.size() - 1; hi > lo; hi--){
                if(hi < nums.size() - 1 && nums[hi] == nums[hi + 1]) continue;
                while(nums[lo] < -(nums[i] + nums[hi])) lo++;
                if(lo < hi && (nums[i] + nums[lo] + nums[hi]) == 0) res.push_back({nums[i], nums[lo], nums[hi]});
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {-1, 0, 1, 2, -1, -4}; // Input vector
    vector<vector<int>> result = solution.threeSum(nums); // Call the function

    // Print the output
    cout << "Output: ";
    for (auto vec : result) {
        cout << "[";
        for (int i = 0; i < vec.size(); ++i) {
            cout << vec[i];
            if (i < vec.size() - 1) cout << ", ";
        }
        cout << "]";
    }
    cout << endl;

    return 0;
}
