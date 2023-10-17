#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m - 1, j = n - 1; j >= 0;) {
            nums1[i + j + 1] = (i < 0 || nums1[i] < nums2[j]) ? nums2[j--] : nums1[i--];
        }
    }
};

// Function to print the elements of a vector
template <typename T>
void printVector(const vector<T>& vec) {
    for (const auto& elem : vec) {
        cout << elem << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;
    Solution sol;
    sol.merge(nums1, m, nums2, n);
    printVector(nums1);
    return 0;
}
