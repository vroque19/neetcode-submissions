# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        # leaf nodes get set to nullptr
        if not root:
            return root
        
        if root.val > key:
            root.left = self.deleteNode(root.left, key)
        elif root.val < key:
            root.right = self.deleteNode(root.right, key)
        else:
            if not root.right:
                return root.left
            elif not root.left:
                return root.right
            else:
                # find our in order predecessor (left subtrees greatest node)
                curr = root.left
                while curr.right:
                    curr = curr.right
                root.val = curr.val
                root.left = self.deleteNode(root.left, curr.val)
        return root

        # nodes that have one child get set to that child
        # nodes that have two children get set to one of the children
        # nodes with grandchildren cannot arbitrarily choose a child to be replaced by
        # we must keep the BST balanced
        # we either have to choose the next in-order predecessor or the in order successor
