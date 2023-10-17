#include <iostream>
#include <vector>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> res;
        std::stack<TreeNode*> s;
        auto p = root;
        while (p || !s.empty()) {
            if (!p) {
                p = s.top();
                s.pop();
            }
            res.push_back(p->val);
            if (p->right) s.push(p->right);
            p = p->left;
        }
        return res;
    }
};

// Utility function to create a sample binary tree
TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    return root;
}

// Test the code
int main() {
    Solution sol;
    TreeNode* root = createSampleTree();
    std::vector<int> result = sol.preorderTraversal(root);

    // Print the output
    std::cout << "Preorder Traversal: ";
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i];
        if (i != result.size() - 1) {
            std::cout << " -> ";
        }
    }
    std::cout << std::endl;

    // Freeing memory
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
