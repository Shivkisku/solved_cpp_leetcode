#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if (!root) return res;
        DFS(root, res, vector<int>(), 0, sum);
        return res;
    }
    
    void DFS(TreeNode* root, vector<vector<int>>& res, vector<int> path, int sum, int target) {
        if (!root) return;
        path.push_back(root->val);
        sum += root->val;
        if (!root->left && !root->right) {
            if (sum == target) res.push_back(path);
            return;
        }
        DFS(root->left, res, path, sum, target);
        DFS(root->right, res, path, sum, target);
    }
};

int main() {
    // Test your inputs here
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right->right = new TreeNode(5);

    int sum = 22;

    Solution sol;
    vector<vector<int>> result = sol.pathSum(root, sum);
    cout << "Result: " << endl;
    for (const auto &vec : result) {
        cout << "[ ";
        for (const auto &num : vec) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}
