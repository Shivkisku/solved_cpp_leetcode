#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> comb;
        backtrack(res, candidates, 0, 0, target, comb);
        return res;
    }

    void backtrack(vector<vector<int>>& res, vector<int>& candidates, int pos, int sum, int target, vector<int>& comb) {
        if (sum > target || pos == candidates.size()) return;
        if (sum == target) {
            res.push_back(comb);
            return;
        }
        backtrack(res, candidates, pos + 1, sum, target, comb);
        comb.push_back(candidates[pos]);
        backtrack(res, candidates, pos, sum + candidates[pos], target, comb);
        comb.pop_back();
    }
};

int main() {
    Solution sol;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> result = sol.combinationSum(candidates, target);
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
