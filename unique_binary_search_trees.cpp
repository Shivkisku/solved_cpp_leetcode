#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return DFS(1, n);
    }
    
    vector<TreeNode*> DFS(int l, int r) {
        vector<TreeNode*> res;
        if (l > r) return {NULL};
        for (int i = l; i <= r; i++) {
            auto left = DFS(l, i - 1);
            auto right = DFS(i + 1, r);
            for (auto x : left) {
                for (auto y : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = x;
                    root->right = y;
                    res.push_back(root);
                }    
            }
        }
        return res;
    }
};

// Function to print the elements of a vector of TreeNode pointers
void printTrees(const vector<TreeNode*>& trees) {
    for (auto tree : trees) {
        // Print the tree elements here
        // You can create another function to print the tree structure
        // Example: printTree(tree);
    }
    // You can print additional information if needed
    cout << "Number of trees generated: " << trees.size() << endl;
}

int main() {
    int n = 3; // Change the value of n as needed
    Solution sol;
    vector<TreeNode*> result = sol.generateTrees(n);
    printTrees(result);
    return 0;
}
