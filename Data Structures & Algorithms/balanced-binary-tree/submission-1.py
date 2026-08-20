# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def isBalancedHelper(root):
            if root is None:
                return [True, 0]
            bal = False
            left = isBalancedHelper(root.left)
            right = isBalancedHelper(root.right)
            print(left[1], right[1])
            h = 1 + max(left[1], right[1])
            if abs(left[1]-right[1])<=1 and left[0] and right[0]:
                bal = True
            return [bal, h]
        return isBalancedHelper(root)[0]