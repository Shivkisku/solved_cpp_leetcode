#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size() == 0) return res;
        int minR = 0, maxR = matrix.size() - 1, minC = 0, maxC = matrix[0].size() - 1;
        while (minR <= maxR && minC <= maxC) {
            for (int i = minC; i <= maxC; i++) res.push_back(matrix[minR][i]);
            minR++;
            for (int i = minR; i <= maxR; i++) res.push_back(matrix[i][maxC]);
            maxC--;
            for (int i = maxC; i >= minC && minR <= maxR; i--) res.push_back(matrix[maxR][i]);
            maxR--;
            for (int i = maxR; i >= minR && minC <= maxC; i--) res.push_back(matrix[i][minC]);
            minC++;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> result = sol.spiralOrder(matrix);
    cout << "Output: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;
    return 0;
}
