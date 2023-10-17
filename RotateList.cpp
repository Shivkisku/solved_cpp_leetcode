#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;

        int len = 0;
        ListNode* p = head;
        while (p) {
            p = p->next;
            len++;
        }
        k = k % len;
        if (k == 0) return head;

        ListNode* slow = head;
        ListNode* fast = head;
        while (k > 0) {
            fast = fast->next;
            k--;
        }
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* res = slow->next;

        slow->next = nullptr;
        fast->next = head;

        return res;
    }
};

// Function to print the linked list
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val;
        if (current->next != nullptr) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << endl;
}

int main() {
    // Create the example linked list
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Create a solution object
    Solution solution;

    // Define the value of k
    int k = 2;

    // Call the rotateRight function
    ListNode* result = solution.rotateRight(head, k);

    // Print the output
    cout << "Rotated Linked List: ";
    printLinkedList(result);

    return 0;
}
