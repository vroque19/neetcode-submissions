class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        ans = 0
        if len(tokens) == 1:
            return int(tokens[0])
        for t in tokens:
            if t.isnumeric():
                stack.append(t)
            elif t[0] == '-' and len(t)>1:
                stack.append(t)
            else:
                print(stack)
                a = str(stack.pop())
                b = str(stack.pop())
                ans = int(eval(b + t + a))
                stack.append(ans)
        return ans