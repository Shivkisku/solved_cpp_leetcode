#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(nums, 0, vector<int>(), res);
        return res;
    }

    void backtrack(vector<int>& nums, int k, vector<int> subset, vector<vector<int>>& res) {
        if (k == nums.size()) {
            res.push_back(subset);
            return;
        }
        backtrack(nums, k + 1, subset, res);
        subset.push_back(nums[k]);
        backtrack(nums, k + 1, subset, res);
    }
};

// Function to print the vector of vectors
void printSubsets(vector<vector<int>>& subsets) {
    cout << "Output:" << endl;
    for (auto subset : subsets) {
        cout << "[";
        for (int num : subset) {
            cout << num << ", ";
        }
        cout << "], ";
    }
    cout << endl;
}

int main() {
    // Example input
    vector<int> nums = {1, 2, 3};

    // Create a solution object
    Solution solution;

    // Call the subsets function
    vector<vector<int>> result = solution.subsets(nums);

    // Print the output
    printSubsets(result);

    return 0;
}
