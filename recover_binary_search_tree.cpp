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
    void recoverTree(TreeNode* root) {
        TreeNode* pre = nullptr, *one = nullptr, *two = nullptr;
        DFS(root, pre, one, two);
        swap(one->val, two->val);
    }
    
    void DFS(TreeNode* cur, TreeNode* &pre, TreeNode* &one, TreeNode* &two) {
        if (!cur) return;
        DFS(cur->left, pre, one, two);
        if (pre && cur->val < pre->val) {
            if (!one) one = pre;
            two = cur;
        }
        pre = cur;
        DFS(cur->right, pre, one, two);
    }
};

// Function to print the inorder traversal of the tree
void printInorder(TreeNode* root) {
    if (root) {
        printInorder(root->left);
        cout << root->val << " ";
        printInorder(root->right);
    }
}

int main() {
    // Test your inputs here
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->right = new TreeNode(2);

    Solution sol;
    sol.recoverTree(root);
    cout << "Inorder traversal after recovery: ";
    printInorder(root);
    cout << endl;
    return 0;
}
