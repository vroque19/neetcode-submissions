# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        # bfs each tree at the same time
        # if at any point the current nodes of each tree dont match return false
        if not p or not q:
            return p == q
        qp = deque()
        qq = deque()
        qp.append(p)
        qq.append(q)
        
        while qq and qp:
            if qp[0].left and qq[0].left:
                qp.append(qp[0].left)
                qq.append(qq[0].left)
            elif not qp[0].left and not qq[0].left:
                pass
            else:
                return False
            if qp[0].right and qq[0].right:
                qp.append(qp[0].right)
                qq.append(qq[0].right)
            elif not qp[0].right and not qq[0].right:
                pass
            else:
                print(qq[0], qp[0].right)
                return False
            if qp.popleft().val != qq.popleft().val:
                return False
        return True
