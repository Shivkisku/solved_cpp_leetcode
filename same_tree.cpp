#include <iostream>
#include <queue>

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
    // DFS
    bool isSameTreeDFS(TreeNode* p, TreeNode* q) {
        if (!p || !q) {
            return !p && !q;
        }
        if (p->val != q->val) {
            return false;
        }
        return isSameTreeDFS(p->left, q->left) && isSameTreeDFS(p->right, q->right);
    }

    // BFS
    bool isSameTreeBFS(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> pq, qq;
        pq.push(p);
        qq.push(q);
        while (!pq.empty() && !qq.empty()) {
            auto a = pq.front();
            pq.pop();
            auto b = qq.front();
            qq.pop();
            if (!a || !b) {
                if (!a && !b) {
                    continue;
                } else {
                    return false;
                }
            }

            if (a->val != b->val) {
                return false;
            }

            pq.push(a->left);
            pq.push(a->right);

            qq.push(b->left);
            qq.push(b->right);
        }
        return true;
    }
};

int main() {
    // Test your inputs here
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    Solution sol;
    cout << "DFS Result: " << (sol.isSameTreeDFS(p, q) ? "true" : "false") << endl;
    cout << "BFS Result: " << (sol.isSameTreeBFS(p, q) ? "true" : "false") << endl;
    return 0;
}
