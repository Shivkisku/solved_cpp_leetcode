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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        TreeNode* root = new TreeNode(nums[nums.size() / 2]);
        vector<int> left(nums.begin(), nums.begin() + nums.size() / 2);
        vector<int> right(nums.begin() + nums.size() / 2 + 1, nums.end());
        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);
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
    vector<int> nums = {-10, -3, 0, 5, 9};

    Solution sol;
    TreeNode* result = sol.sortedArrayToBST(nums);
    cout << "Result: ";
    printInorder(result);
    cout << endl;
    return 0;
}
