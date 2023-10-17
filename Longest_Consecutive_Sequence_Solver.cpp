#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        int res = 0;
        for (int& x: nums) {
            if (m[x]) {
                continue;
            }
            int l = m[x - 1];
            int r = m[x + 1];
            m[x] = l + r + 1;
            m[x - l] = l + r + 1;
            m[x + r] = l + r + 1;
            res = max(res, m[x]);
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    int result = solution.longestConsecutive(nums);
    cout << "Length of the longest consecutive sequence: " << result << endl;

    return 0;
}
