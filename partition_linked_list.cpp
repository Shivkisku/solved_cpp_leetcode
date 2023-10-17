#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode left(0);
        ListNode right(0);
        ListNode* l = &left;
        ListNode* r = &right;
        ListNode* cur = head;
        while (cur) {
            if (cur->val < x) {
                l->next = cur;
                l = l->next;
            } else {
                r->next = cur;
                r = r->next;
            }
            cur = cur->next;
        }
        r->next = nullptr;
        l->next = right.next;
        return left.next;
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
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);
    int x = 3;
    Solution sol;
    ListNode* result = sol.partition(head, x);
    printList(result);
    return 0;
}
