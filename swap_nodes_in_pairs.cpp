#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode res(0);
        ListNode *pre = &res, *one = head, *two = head->next;
        while (one && two) {
            one->next = two->next;
            two->next = one;
            pre->next = two;
            pre = one;
            one = one->next;
            if (one) two = one->next;
        }
        return res.next;
    }
};

// Function to print the linked list
void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val;
        if (head->next != nullptr) {
            std::cout << " -> ";
        }
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Solution solution;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4); // Assuming you have a ListNode as input

    ListNode* result = solution.swapPairs(head); // Call the function

    // Print the resulting linked list
    printLinkedList(result);

    return 0;
}
