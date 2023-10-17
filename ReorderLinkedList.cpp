#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head) return;
        ListNode* slow = head, *fast = head;
        ListNode* pre = new ListNode(0);
        pre->next = slow;
        while(fast && fast->next){
            pre = pre->next;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast) slow = slow->next, pre = pre->next;
        pre->next = NULL;
        ListNode* cur, *next;
        pre = NULL, cur = slow;
        while(cur){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        ListNode* h1 = head, *h2 = pre, *p1, *p2;
        while(h1 && h2){
            p1 = h1->next;
            p2 = h2->next;
            h1->next = h2;
            h2->next = p1;
            h1 = p1;
            h2 = p2;
        }
    }
};

// Utility function to print the linked list
void printLinkedList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        std::cout << temp->val;
        if (temp->next != nullptr) {
            std::cout << " -> ";
        }
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Test the code
int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    Solution sol;
    sol.reorderList(head);

    // Print the reordered linked list
    printLinkedList(head);

    // Freeing memory
    while (head != nullptr) {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
