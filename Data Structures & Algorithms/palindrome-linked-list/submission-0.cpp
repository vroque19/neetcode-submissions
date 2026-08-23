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
    // convert linked list to a vector
    vector<int> toList(ListNode* newNode) {
        vector<int> arr;
        while(newNode) {
            arr.push_back(newNode->val);
            newNode = newNode->next;
        }
        return arr;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* node = head;
        if(!head->next) { return true; }
        vector<int> arr = toList(node);
        int p1 = 0;
        int p2 = size(arr)-1;
        while(p1<p2) {
            if(arr[p1] != arr[p2]) {
                return false;
            }
            p1++;
            p2--;
        }
        return true;
    }
};