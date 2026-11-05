/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        /*
            head
            NULL <- 1 -> 2,  3,  4,  5]

            3 pointers: prev next current
            store next
            point current to prev then repeat in a loop
            at the end return prev
        */

        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;
        
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }
};
