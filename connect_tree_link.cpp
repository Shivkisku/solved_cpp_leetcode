#include <iostream>
#include <deque>

using namespace std;

// Definition for a binary tree node
struct TreeLinkNode {
    int val;
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
    TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        deque<TreeLinkNode*> cur;
        deque<TreeLinkNode*> next;
        cur.push_back(root);
        while (!cur.empty()) {
            TreeLinkNode* node = cur.front();
            cur.pop_front();
            node->next = cur.empty() ? nullptr : cur.front();
            if (node->left) next.push_back(node->left);
            if (node->right) next.push_back(node->right);
            if (cur.empty()) swap(cur, next);
        }
    }
};

int main() {
    // Test your inputs here
    TreeLinkNode* root = new TreeLinkNode(1);
    root->left = new TreeLinkNode(2);
    root->right = new TreeLinkNode(3);
    root->left->left = new TreeLinkNode(4);
    root->left->right = new TreeLinkNode(5);
    root->right->right = new TreeLinkNode(7);

    Solution sol;
    sol.connect(root);

    // Print the next pointers
    while (root) {
        TreeLinkNode* current = root;
        while (current) {
            cout << current->val << " ";
            current = current->next;
        }
        cout << endl;
        root = root->left;
    }

    return 0;
}
