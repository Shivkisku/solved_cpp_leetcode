#include <iostream>
#include <vector>
#include <deque>

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        deque<TreeNode*> cur;
        deque<TreeNode*> next;
        cur.push_back(root);
        int level = 0;
        res.push_back(vector<int>());
        while (!cur.empty()) {
            TreeNode* node = cur.front();
            cur.pop_front();
            if (node->left) next.push_back(node->left);
            if (node->right) next.push_back(node->right);
            res[level].push_back(node->val);
            if (cur.empty() && !next.empty()) {
                res.push_back(vector<int>());
                level++;
                swap(cur, next);
            }
        }
        return res;
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
    vector<vector<int>> result = sol.levelOrder(root);
    cout << "Result: ";
    printVector(result);
    return 0;
}
