/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* shadowA = headA;
        ListNode* shadowB = headB;

        while(shadowA) {
            shadowB = headB;
            while(shadowB) {
                if(shadowA == shadowB) {
                    return shadowA;
                }
                shadowB = shadowB->next;
                }
            shadowA = shadowA->next;
        }
        return nullptr;
    }
};