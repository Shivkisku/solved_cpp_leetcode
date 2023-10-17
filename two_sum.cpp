#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++){
            if(m.count(target - nums[i])) return {m[target - nums[i]], i};
            m[nums[i]] = i;
        }
        return {}; // added this line to handle cases where no solution is found
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 7, 11, 15}; // Input vector
    int target = 9; // Input target
    vector<int> result = solution.twoSum(nums, target); // Call the function

    // Print the output
    cout << "Output: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
