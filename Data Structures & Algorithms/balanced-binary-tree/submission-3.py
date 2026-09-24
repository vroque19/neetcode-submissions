# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True

        def getHeight(root: Optional[TreeNode])->int:
            if not root:
                return 0
         
            return max(1 + getHeight(root.right), 1 + getHeight(root.left))

        stack = []
        stack.append(root)
        isBalanced = True
        left_height = 0
        right_height = 0
        while(stack):
            curr = stack.pop()
            print(curr.val)
            right_height = getHeight(curr.right)
            left_height = getHeight(curr.left)
            if abs(right_height-left_height) > 1:
                isBalanced = False
                break
            if curr.right:
                stack.append(curr.right)
            if curr.left:
                stack.append(curr.left)
        return isBalanced
            
