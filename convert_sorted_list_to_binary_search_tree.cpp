#include <iostream>

using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return new TreeNode(head->val);
        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode* pre = new ListNode(0);
        pre->next = slow;
        // Root is the mid position of the linked list
        while (fast) {
            slow = slow->next;
            pre = pre->next;
            fast = fast->next ? fast->next->next : nullptr;
        }
        TreeNode* root = new TreeNode(slow->val);
        pre->next = nullptr;
        // Call recursively to left and right part of linked list
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
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
    ListNode* head = new ListNode(-10);
    head->next = new ListNode(-3);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(9);

    Solution sol;
    TreeNode* result = sol.sortedListToBST(head);
    cout << "Result: ";
    printInorder(result);
    cout << endl;
    return 0;
}
