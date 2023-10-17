#include <iostream>

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
    bool isValidBST(TreeNode* root) {
        return isValid(root, nullptr, nullptr);
    }
    
    bool isValid(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if (!root) return true;
        if ((minNode && root->val <= minNode->val) || (maxNode && root->val >= maxNode->val)) return false;
        return isValid(root->left, minNode, root) && isValid(root->right, root, maxNode);
    }
};

int main() {
    // Test your inputs here
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    Solution sol;
    bool result = sol.isValidBST(root);
    cout << "Result: " << (result ? "true" : "false") << endl;
    return 0;
}
