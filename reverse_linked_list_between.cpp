#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* l = new ListNode(0);
        l->next = head;
        int x = m, y = n - m;
        while (--x) l = l->next;
        ListNode* pre = l->next, *cur = pre->next, *next;
        while (y--) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        l->next->next = cur;
        l->next = pre;
        return m == 1 ? pre : head;
    }
};

// Function to print the linked list
void printList(ListNode* node) {
    while (node != nullptr) {
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int m = 2, n = 4;
    Solution sol;
    ListNode* result = sol.reverseBetween(head, m, n);
    printList(result);
    return 0;
}
