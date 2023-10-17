#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        for (int i = 0; i <= high;) {
            if (nums[i] == 0) {
                swap(nums[i++], nums[low++]);
            } else if (nums[i] == 2) {
                swap(nums[i], nums[high--]);
            } else {
                i++;
            }
        }
    }
};

// Function to print the vector
void printVector(vector<int>& nums) {
    cout << "Output: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    // Example vector
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    // Create a solution object
    Solution solution;

    // Call the sortColors function
    solution.sortColors(nums);

    // Print the output
    printVector(nums);

    return 0;
}
