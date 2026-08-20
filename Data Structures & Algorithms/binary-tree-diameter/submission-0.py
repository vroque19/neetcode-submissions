# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        
        diameter = self.getDepth(root.right) + self.getDepth(root.left)
        diam_right = self.diameterOfBinaryTree(root.right)
        diam_left = self.diameterOfBinaryTree(root.left)
        return max(diameter, diam_right, diam_left)

    def getDepth(self, node: Optional[TreeNode]) -> int:
        if node is None:
            return 0
        
        depth = 1
        dl = self.getDepth(node.left)
        dr = self.getDepth(node.right)
        return depth + max(dl, dr)
