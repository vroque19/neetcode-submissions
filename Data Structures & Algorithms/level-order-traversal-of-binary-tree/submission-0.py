# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        ans = []
        if not root:
            return []
        q = deque()
        q.append(root)
        while q:
            curr_list = []
            level_size = len(q)
            for i in range(level_size):
                curr = q.popleft()
                curr_list.append(curr.val)
                if curr.left:
                    q.append(curr.left)
                if curr.right:
                    q.append(curr.right)
            ans.append(curr_list)

        return ans