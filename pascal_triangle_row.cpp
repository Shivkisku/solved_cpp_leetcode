#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) return {1};
        auto v = getRow(rowIndex - 1);
        int n = v.size();
        for (int i = 1; i < n; i++)
            v[i] = (i <= n / 2) ? v[i] + v[n - i] : v[n - i];
        v.push_back(1);
        return v;
    }
};

// Helper function to print the output
void printOutput(vector<int>& output) {
    for (auto num : output) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    // Test your inputs here
    int rowIndex = 3;

    Solution sol;
    vector<int> output = sol.getRow(rowIndex);

    // Print the output
    cout << "Output: " << endl;
    printOutput(output);

    return 0;
}
