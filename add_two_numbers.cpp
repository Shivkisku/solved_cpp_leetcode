#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head(0);
        ListNode* cur = &head;
        int carry = 0;
        while (l1 || l2 || carry) {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;

            ListNode* node = new ListNode((x + y + carry) % 10);
            cur->next = node;
            cur = node;

            carry = (x + y + carry) / 10;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return head.next;
    }
};

// Helper function to print the linked list
void printList(ListNode* node) {
    while (node != nullptr) {
        std::cout << node->val;
        if (node->next != nullptr) {
            std::cout << " -> ";
        }
        node = node->next;
    }
    std::cout << std::endl;
}

int main() {
    Solution solution;
    // Create sample linked lists
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode* result = solution.addTwoNumbers(l1, l2);

    // Print the output
    std::cout << "Output: ";
    printList(result);

    // Clean up the memory
    while (l1 != nullptr) {
        ListNode* temp = l1;
        l1 = l1->next;
        delete temp;
    }
    while (l2 != nullptr) {
        ListNode* temp = l2;
        l2 = l2->next;
        delete temp;
    }
    while (result != nullptr) {
        ListNode* temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}
