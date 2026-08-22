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

class Solution {

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // stack to keep track of digits we see in order
        // 1 -> 2 -> 3 = 321
        // 4 -> 5 -> 6 = 654
        // 321 + 654 = 975
        int carry = 0; // normal addition
        ListNode* res = new ListNode();
        ListNode* curr = res;
        while(l1 && l2) {
            int curr_sum = l1->val + l2->val + carry;
            carry = (curr_sum>9) ? 1 : 0;
            curr->next = new ListNode(curr_sum%10);
            l1 = l1->next;
            l2 = l2->next;
            curr = curr->next;
        }
        while(l1) {
            int curr_sum = l1->val + carry;
            carry = (curr_sum>9) ? 1 : 0;
            curr->next = new ListNode(curr_sum%10);
            l1 = l1->next;
            curr = curr->next;
        }
        while(l2) {
            int curr_sum = l2->val + carry;
            carry = (curr_sum>9) ? 1 : 0;
            curr->next = new ListNode(curr_sum%10);
            l2 = l2->next;
            curr = curr->next;
        }
        if(carry) {
            curr->next = new ListNode(carry);
        }



        return res->next;
    }
};
