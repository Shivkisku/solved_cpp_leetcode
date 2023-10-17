#include <iostream>
#include <unordered_map>
using namespace std;

/**
 * Definition for singly-linked list with a random pointer.
 */
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode*>m;
        auto p = head;
        while(p){
            m[p] = new RandomListNode(p->label);
            p = p->next;
        }
        p = head;
        while(p){
            m[p]->next = m[p->next];
            m[p]->random = m[p->random];
            p = p->next;
        }
        return m[head];
    }
};

// Function to print the output
void printList(RandomListNode *head) {
    while (head != nullptr) {
        cout << "Label: " << head->label;
        if (head->random != nullptr) {
            cout << ", Random: " << head->random->label;
        }
        cout << endl;
        head = head->next;
    }
}

int main() {
    Solution sol;
    // Sample input construction
    RandomListNode *node1 = new RandomListNode(1);
    RandomListNode *node2 = new RandomListNode(2);
    RandomListNode *node3 = new RandomListNode(3);
    node1->next = node2;
    node2->next = node3;
    node1->random = node3;
    node2->random = node1;
    node3->random = node2;

    RandomListNode *result = sol.copyRandomList(node1);
    printList(result);

    return 0;
}
