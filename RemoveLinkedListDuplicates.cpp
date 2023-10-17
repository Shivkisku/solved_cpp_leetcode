#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode res(0);
        res.next = head;
        ListNode* pre = &res, *cur = head, *next = cur ? cur->next : NULL;
        while (cur) {
            bool dup = false;
            while (next && next->val == cur->val) {
                dup = true;
                next = next->next;
            }
            if (dup) {
                cur = next;
                next = next ? next->next : NULL;
                pre->next = cur;
            } else {
                pre = cur;
                cur = next;
                next = next ? next->next : NULL;
            }
        }
        return res.next;
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
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);

    // Create a solution object
    Solution solution;

    // Call the deleteDuplicates function
    ListNode* result = solution.deleteDuplicates(head);

    // Print the output
    cout << "Output: ";
    printLinkedList(result);

    return 0;
}
