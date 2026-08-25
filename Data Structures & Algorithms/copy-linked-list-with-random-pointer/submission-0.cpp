/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
10:13
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Node* deep_copy = head;
        Node* curr = head;
        if(!head) {
            return head;
        }
        map<Node*, Node*> random_ptrs;
        // traverse through head map each node to its copy
        while(curr)
        {
            random_ptrs[curr] = new Node(curr->val);
            curr = curr->next;
        }

        Node* deep_copy = nullptr;
        curr = head;
        // traverse a second time and assign the new list to point to the new copy
        while(curr) {
            deep_copy = random_ptrs[curr];
            deep_copy->random = random_ptrs[curr->random];
            deep_copy->next = random_ptrs[curr->next];
            curr = curr->next;
        }
        return random_ptrs[head];
    }
};
