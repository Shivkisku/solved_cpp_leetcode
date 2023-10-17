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
    bool isSymmetric(TreeNode* root) {
        vector<vector<TreeNode*>> v;
        dfs(root, v, 0);
        return check(v);
    }
    
    void dfs(TreeNode* root, vector<vector<TreeNode*>>& v, int level) {
        if (level == v.size()) v.push_back({});
        v[level].push_back(root);
        if (!root) return;
        dfs(root->left, v, level + 1);
        dfs(root->right, v, level + 1);
    }
    
    bool check(vector<vector<TreeNode*>>& v) {
        for (auto x : v) {
            int l = 0, r = x.size() - 1;
            while (l < r) {
                auto a = x[l++];
                auto b = x[r--];
                if ((!a || !b) && (a || b) || (a && b) && (a->val != b->val)) return false;
            }
        }
        return true;
    }
};

int main() {
    // Test your inputs here
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution sol;
    bool result = sol.isSymmetric(root);
    cout << "Result: " << (result ? "true" : "false") << endl;
    return 0;
}
