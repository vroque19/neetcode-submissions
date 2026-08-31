/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
    n
 3->2->1->null
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) {
            return nullptr;
        }
        // new head we want to return
        ListNode* new_head = head; // 3 /
        // if there is a next node we can continue reversing the list
        if(head->next) {
            new_head = reverseList(head->next); // 2->null
            head->next->next = head;
        }
        // 1->2->3->null
        head->next = nullptr;
        return new_head;
        
    }
};
