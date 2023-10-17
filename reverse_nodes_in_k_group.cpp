#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* pre = &dummy, *cur = head, *next, *tmp, *p, *ppre, *ccur;
        while(cur){
            p = cur;
            for(int i = 1; i < k && p; i++) p = p->next;
            if(!p) break;
            ppre = pre;
            ccur = cur;
            pre = p->next;
            tmp = p->next;
            while(cur != tmp){
                next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;
            }
            ppre->next = pre;
            pre = ccur;
        }
        return dummy.next;
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

    int k = 2; // Value of k

    ListNode* result = solution.reverseKGroup(head, k); // Call the function

    // Print the resulting linked list
    printLinkedList(result);

    return 0;
}
