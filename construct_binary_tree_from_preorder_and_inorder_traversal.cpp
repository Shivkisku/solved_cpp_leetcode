#include <iostream>
#include <vector>
#include <unordered_map>

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> m;
        for (int i = 0; i < inorder.size(); i++) m[inorder[i]] = i;
        return helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, m);
    }

    TreeNode* helper(vector<int>& preorder, int pStart, int pEnd, vector<int>& inorder, int iStart, int iEnd, unordered_map<int, int>& m) {
        if (pStart > pEnd) return nullptr;
        TreeNode* root = new TreeNode(preorder[pStart]);
        int i = m[preorder[pStart]];
        root->left = helper(preorder, pStart + 1, pStart + i - iStart, inorder, iStart, i - 1, m);
        root->right = helper(preorder, pStart + i - iStart + 1, pEnd, inorder, i + 1, iEnd, m);
        return root;
    }
};

// Function to print the elements of a tree using inorder traversal
void printInorder(TreeNode* root) {
    if (root) {
        printInorder(root->left);
        cout << root->val << " ";
        printInorder(root->right);
    }
}

int main() {
    // Test your inputs here
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution sol;
    TreeNode* result = sol.buildTree(preorder, inorder);
    cout << "Result: ";
    printInorder(result);
    cout << endl;
    return 0;
}
