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
    ListNode* middleNode(ListNode* head) {
        ListNode* curr = head;
        int length = 0;
        while(curr) {
            curr = curr->next;

            length++;
        }
        int j = 0;
        curr = head;
        while(j < length / 2) {
            curr = curr->next;
            j++;
        }
        return curr;
    }
};