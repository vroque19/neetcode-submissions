# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        # a node is good if it has no ancestors with value > itself
        # traverse the tree and each node that is greater than or equal to 
        # itself can increment the good count
        largest = root.val
        stack = [(root, root.val)]
        ans = 0
        while stack:
            curr_node = stack.pop()
            curr = curr_node[0]
            curr_max = curr_node[1]
            if curr_max <= curr.val:
                curr_max = curr.val
                ans += 1
            if curr.right:
                stack.append((curr.right, curr_max))
            if curr.left:
                stack.append((curr.left, curr_max))
            
        return ans

