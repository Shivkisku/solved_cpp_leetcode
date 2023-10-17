#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Recursive
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        auto p = deleteDuplicates(head->next);
        head->next = p;
        return p->val == head->val ? p : head;
    }
};

// Non-recursive
class Solution2 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* pre = head, *cur = head->next;
        while (cur) {
            pre->val == cur->val ? pre->next = cur->next : pre = cur;
            cur = cur->next;
        }
        return head;
    }
};

// Function to print the linked list
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        cout << current->val;
        if (current->next) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << endl;
}

int main() {
    // Example input
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    // Create a solution object
    Solution solution;

    // Call the deleteDuplicates function
    ListNode* result = solution.deleteDuplicates(head);

    // Print the output
    cout << "Output: ";
    printLinkedList(result);

    return 0;
}
