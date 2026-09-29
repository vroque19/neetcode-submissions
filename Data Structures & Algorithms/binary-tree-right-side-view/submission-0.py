# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        # for each level in the tree
        # append the rightmost node
        if not root:
            return []
        ans = []
        q = deque()
        q.append(root)
        while q:
            level_len = len(q)
            # append all the nodes of the next level to the q
            for i in range(level_len):
                curr = q.popleft()
                if curr.left:
                    q.append(curr.left)
                if curr.right:
                    q.append(curr.right)
                # append the last (rightmost node) to the answer
                if i == level_len - 1:
                    ans.append(curr.val)
        return ans


                
            


