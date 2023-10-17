#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = 0;
        while(j != nums.size())
            if(nums[j] == val) j++;
            else nums[i++] = nums[j++];
        return i;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {3, 2, 2, 3};
    int val1 = 3;

    vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
    int val2 = 2;

    int result1 = sol.removeElement(nums1, val1);
    int result2 = sol.removeElement(nums2, val2);

    cout << "Result 1: " << result1 << endl;
    cout << "Modified Array 1: ";
    for (int i = 0; i < result1; i++) {
        cout << nums1[i] << " ";
    }
    cout << endl;

    cout << "Result 2: " << result2 << endl;
    cout << "Modified Array 2: ";
    for (int i = 0; i < result2; i++) {
        cout << nums2[i] << " ";
    }
    cout << endl;

    return 0;
}
