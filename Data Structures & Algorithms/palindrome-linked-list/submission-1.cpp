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
    bool isPalindrome(ListNode* head) {
        ListNode* curr = head;
        vector<int> l1;
        
        while(curr) {
            l1.push_back(curr->val);
            curr = curr->next;
        }
        int p1 = 0;
        int p2 = l1.size()-1;
        
        while(p1 < p2) {
            if(l1[p1] != l1[p2]) {
                return false;
            }
            p1++;
            p2--;
        }
        return true;
    }
};