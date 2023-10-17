#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        auto one = head, two = head, meet = head;
        while(two && two->next){
            one = one->next;
            two = two->next->next;
            if(one == two){
                meet = one;
                break;
            }
        }
        if(!two || !two->next) return NULL;
        auto p = head;
        while(p != meet){
            p = p->next;
            meet = meet->next;
        }
        return p;
    }
};

// Test the code
int main() {
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next; // creating a cycle

    Solution sol;
    ListNode *result = sol.detectCycle(head);
    if (result) {
        std::cout << "Cycle begins at node with value: " << result->val << std::endl;
    } else {
        std::cout << "No cycle found." << std::endl;
    }

    // Freeing memory
    head->next->next->next->next = nullptr;
    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;

    return 0;
}
