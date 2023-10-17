#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> path;
        DFS(res, candidates, 0, 0, target, path);
        return res;
    }

    void DFS(vector<vector<int>>& res, vector<int>& candidates, int pos, int sum, int target, vector<int>& path) {
        if (sum >= target) {
            if (sum == target) res.push_back(path);
            return;
        }
        for (int i = pos; i < candidates.size(); i++) {
            if (i != pos && candidates[i] == candidates[i - 1]) continue;
            path.push_back(candidates[i]);
            DFS(res, candidates, i + 1, sum + candidates[i], target, path);
            path.pop_back();
        }
    }
};

int main() {
    Solution sol;
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> result = sol.combinationSum2(candidates, target);
    cout << "Output: ";
    for (const auto& v : result) {
        cout << "[";
        for (int num : v) {
            cout << num << ", ";
        }
        cout << "] ";
    }
    cout << endl;
    return 0;
}
