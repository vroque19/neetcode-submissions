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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* shadow = head;
        int len = 0;
        while(shadow) {
            shadow = shadow->next;
            len++;
            cout << len << endl;
        }
        if(len == 1) {
            return nullptr;
        }
        shadow = head;
        if(len - n == 0) {
            cout << "length is 0" << endl;
            cout << shadow->val;
            return head->next;
        }
        cout << "Shadow: " << shadow->val << len-n << endl;
        for(int i = 1; i < len - n; i++) {
            shadow = shadow->next;
        }
        cout << "Shadow: " << shadow->val << endl;

        cout << shadow->val;
        ListNode* temp = shadow->next;
        shadow->next = temp->next;
        delete temp;

        return head;
    }
};
