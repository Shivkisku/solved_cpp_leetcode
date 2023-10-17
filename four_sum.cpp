#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> path;
        DFS(res, nums, 0, target, 0, 0, path);
        return res;
    }
    
    void DFS(vector<vector<int>>& res, vector<int>& nums, int pos, int target, int count, int sum, vector<int>& path){
        if(count == 4){
            if(sum == target) res.push_back(path);
            return;
        }
        for(int i = pos; i < nums.size(); i++){
            if(i != pos && nums[i] == nums[i - 1]) continue;
            if(sum + nums[i] + (3 - count) * nums[nums.size() - 1] < target) continue;
            if(sum + (4 - count)* nums[i] > target) break;
            path.push_back(nums[i]);
            DFS(res, nums, i + 1, target, count + 1, sum + nums[i], path);
            path.pop_back();
        }
    }
};

// Function to print the output
void printOutput(const vector<vector<int>>& result) {
    cout << "Output: " << endl;
    for (const auto &vec : result) {
        cout << "[";
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i];
            if (i < vec.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
}

int main() {
    Solution solution;
    vector<int> nums = {1, 0, -1, 0, -2, 2}; // Input vector
    int target = 0; // Target integer
    vector<vector<int>> result = solution.fourSum(nums, target); // Call the function

    // Print the output
    printOutput(result);

    return 0;
}
