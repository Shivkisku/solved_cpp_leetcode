#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0;
        while(j < nums.size()){
            while(j < nums.size() - 1 && nums[j] == nums[j + 1]) j++;
            nums[i++] = nums[j++];
        }
        return i;
    }
};

// Function to print the vector
void printVector(const vector<int>& nums, int length) {
    cout << "Output: [";
    for (int i = 0; i < length; i++) {
        cout << nums[i];
        if (i < length - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4}; // Example vector nums

    int result = solution.removeDuplicates(nums); // Call the function

    // Print the output
    printVector(nums, result);

    return 0;
}
