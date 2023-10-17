#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 3) return nums.size();
        int i = 2, j = 2;
        while(j < nums.size())
            if(nums[j] > nums[i - 2]) nums[i++] = nums[j++];
            else j++;
        return i;
    }
};

// Function to print the elements of the vector
void printVector(vector<int>& nums, int size) {
    cout << "Output: ";
    for (int i = 0; i < size; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main() {
    // Example input
    vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};

    // Create a solution object
    Solution solution;

    // Call the removeDuplicates function
    int result = solution.removeDuplicates(nums);

    // Print the output
    printVector(nums, result);

    return 0;
}
