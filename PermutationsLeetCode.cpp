#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        DFS(res, nums, 0);
        return res;        
    }
    
    void DFS(vector<vector<int>>& res, vector<int>& nums, int pos) {
        if (pos == nums.size() - 1) {
            res.push_back(nums);
            return;
        }
        for (int i = pos; i < nums.size(); i++) {
            swap(nums[pos], nums[i]);
            DFS(res, nums, pos + 1);
            swap(nums[pos], nums[i]);
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = sol.permute(nums);
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
