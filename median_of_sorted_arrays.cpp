#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if(m > n) return findMedianSortedArrays(nums2, nums1);
        int lo = 0, hi = m, mid = (m + n + 1) / 2;
        while(lo <= hi){
            int i = (lo + hi) / 2;
            int j = mid - i;
            if(i < m && nums2[j - 1] > nums1[i]) 
                lo = i + 1;
            else if(i > 0  && nums1[i - 1] > nums2[j])
                hi = i - 1;
            else{
                int maxLeft = (i == 0) ? nums2[j - 1] : (j == 0) ? nums1[i - 1] : max(nums1[i - 1], nums2[j - 1]); 
                int minRight = (i == m) ? nums2[j] : (j == n) ? nums1[i] : min(nums1[i], nums2[j]);
                return (m + n) % 2 ? maxLeft : (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0; // Added this line to handle all code paths
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    double result = solution.findMedianSortedArrays(nums1, nums2);

    // Print the output
    cout << "Output: " << result << endl;

    return 0;
}
