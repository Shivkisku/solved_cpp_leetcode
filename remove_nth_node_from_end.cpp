#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow(head), *fast(head);
        while(n--) fast = fast->next;
        if(!fast) return head->next;
        while(fast->next) slow = slow->next, fast = fast->next;
        slow->next = slow->next->next;
        return head;
    }
};

// Helper function to print the linked list
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
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);
    ListNode* fifth = new ListNode(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    int n = 2; // Example value of n
    Solution solution;
    ListNode* result = solution.removeNthFromEnd(head, n);

    // Print the resulting linked list
    printLinkedList(result);

    return 0;
}
