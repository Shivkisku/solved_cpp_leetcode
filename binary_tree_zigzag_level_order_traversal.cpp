#include <iostream>
#include <vector>
#include <deque>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        deque<TreeNode*> cur, next;
        cur.push_back(root);
        vector<int> v;
        int level = 0;
        while (!cur.empty()) {
            auto p = cur.front();
            cur.pop_front();
            v.push_back(p->val);
            if (p->left) next.push_back(p->left);
            if (p->right) next.push_back(p->right);
            if (cur.empty()) {
                if (level++ % 2) reverse(v.begin(), v.end());
                res.push_back(v);
                v.clear();
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
    vector<vector<int>> result = sol.zigzagLevelOrder(root);
    cout << "Result: ";
    printVector(result);
    return 0;
}
