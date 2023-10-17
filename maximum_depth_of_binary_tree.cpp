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
	int maxDepth(TreeNode* root) {
		if (!root) return 0;
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
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
	int result = sol.maxDepth(root);
	cout << "Result: " << result << endl;
	return 0;
}
