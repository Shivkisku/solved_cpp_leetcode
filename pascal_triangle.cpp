#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0) return {};
        if(numRows == 1) return {{1}};
        auto v = generate(numRows - 1);
        auto lastRow = *(v.end() - 1);
        vector<int> res(1, 1);
        for(int i = 0; i < lastRow.size() - 1; i++) res.push_back(lastRow[i] + lastRow[i + 1]);
        res.push_back(1);
        v.push_back(res);
        return v;
    }
};

// Helper function to print the output
void printOutput(vector<vector<int>>& output) {
    for (auto row : output) {
        for (auto num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    // Test your inputs here
    int numRows = 5;

    Solution sol;
    vector<vector<int>> output = sol.generate(numRows);

    // Print the output
    cout << "Output: " << endl;
    printOutput(output);

    return 0;
}
