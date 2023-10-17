#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) {
            return false;
        }
        int lo = 0, hi = matrix.size() - 1;
        int mid = lo + (hi - lo) / 2 + 1;
        while (lo < hi) {
            if (matrix[mid][0] > target) {
                hi = mid - 1;
            } else {
                lo = mid;
            }
            mid = lo + (hi - lo) / 2 + 1;
        }
        auto p = lower_bound(matrix[lo].begin(), matrix[lo].end(), target);
        return p != matrix[lo].end() && *p == target;
    }
};

int main() {
    // Example input
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 3;

    // Create a solution object
    Solution solution;

    // Call the searchMatrix function
    bool result = solution.searchMatrix(matrix, target);

    // Print the output
    cout << "Output: " << (result ? "true" : "false") << endl;

    return 0;
}
