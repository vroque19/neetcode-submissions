/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int findGreatestLeft(TreeNode* curr) {
        while(curr->right) {
            curr = curr->right;
        }
        return curr->val;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        /*
        to keep the BST balanced, removing a node with children requires special handling
        - either the greatest node from the left subtree or the min node from 
        the right subtree need to replace the removal node
                5
              /
            2
           / \
          1   4   
        */
        if(!root) {
            return root;
        }

        if(key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
            if (!root->left ) {
                return root->right;
            } else if(!root->right) {
                return root->left;
            }
            else {

                int greatest_val = findGreatestLeft(root->left);
                root->val = greatest_val;
                root->left = deleteNode(root->left, greatest_val);
            }
        }
        return root;

    }
};