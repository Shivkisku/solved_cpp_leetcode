#include <iostream>
#include <vector>
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> v;
        dfs(root, v, 0);
        reverse(v.begin(), v.end());
        return v;
    }
    
    void dfs(TreeNode* root, vector<vector<int>>& v, int level) {
        if (!root) return;
        if (level == v.size()) v.push_back({});
        v[level].push_back(root->val);
        dfs(root->left, v, level + 1);
        dfs(root->right, v, level + 1);
    }
};

// Function to print the elements of a 2D vector
void printVector(const vector<vector<int>>& vec) {
    for (const auto& v : vec) {
        cout << "[";
        for (const auto& elem : v) {
            cout << elem << " ";
        }
        cout << "] ";
    }
    cout << endl;
}

int main() {
    // Test your inputs here
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<vector<int>> result = sol.levelOrderBottom(root);
    cout << "Result: ";
    printVector(result);
    return 0;
}
