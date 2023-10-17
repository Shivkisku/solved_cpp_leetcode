#include <iostream>
#include <climits>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        DFS(root, maxSum);
        return maxSum;
    }
    
    int DFS(TreeNode* root, int& maxSum){
        if(!root) return 0;
        int left = max(0, DFS(root->left, maxSum));
        int right = max(0, DFS(root->right, maxSum));
        maxSum = max(maxSum, left + right + root->val);
        return max(left, right) + root->val;
    }
};

// Helper function to print the output
void printOutput(int result) {
    cout << "Maximum Path Sum: " << result << endl;
}

int main() {
    // Test your inputs here
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    Solution sol;
    int result = sol.maxPathSum(root);

    // Print the output
    printOutput(result);

    return 0;
}
