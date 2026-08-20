class Solution:
    def isValid(self, s: str) -> bool:
        # '(' must pair with ')'
        # '[' must pair with ']'
        # '{' must pair with '}'
        brackets = {
            ']': '[',
            ')': '(',
            '}': '{'
        }
        stack = []

        for c in s:
            if c in brackets and stack:
                o = stack.pop()
                if brackets[c] != o:
                    return False
            else:
                stack.append(c)
        if not stack:
            return True
        return False

