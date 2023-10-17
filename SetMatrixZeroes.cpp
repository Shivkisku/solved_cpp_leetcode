#include <iostream>
#include <vector>
using namespace std;

// Top-down
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // Implementation here
    }
};

// Bottom-up
class Solution2 {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // Implementation here
    }
};

int main() {
    // Example input
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};

    // Create solution objects
    Solution solution1;
    Solution2 solution2;

    // Call the setZeroes function
    solution1.setZeroes(matrix);
    solution2.setZeroes(matrix);

    // Print the output
    cout << "Output:" << endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
