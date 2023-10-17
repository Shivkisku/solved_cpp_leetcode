#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        DFS(res, nums, 0);
        return res;        
    }
    
    void DFS(vector<vector<int>>& res, vector<int> nums, int pos) {
        if (pos == nums.size() - 1) {
            res.push_back(nums);
            return;
        }
        for (int i = pos; i < nums.size(); i++) {
            if (i != pos && nums[i] == nums[pos]) continue;
            swap(nums[pos], nums[i]);
            DFS(res, nums, pos + 1);
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> result = sol.permuteUnique(nums);
    cout << "Output: ";
    for (const auto& v : result) {
        cout << "[";
        for (int num : v) {
            cout << num << ", ";
        }
        cout << "] ";
    }
    cout << endl;
    return 0;
}
