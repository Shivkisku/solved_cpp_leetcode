#include <iostream>
#include <algorithm>

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
    bool isBalanced(TreeNode* root) {
        bool res = true;
        dfs(root, res);
        return res;
    }
    
    int dfs(TreeNode* root, bool& res) {
        if (!root) return 0;
        int l = dfs(root->left, res);
        int r = dfs(root->right, res);
        if (abs(l - r) > 1) res = false;
        return max(l, r) + 1;
    }
};

int main() {
    // Test your inputs here
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    bool result = sol.isBalanced(root);
    cout << "Result: " << (result ? "true" : "false") << endl;
    return 0;
}
