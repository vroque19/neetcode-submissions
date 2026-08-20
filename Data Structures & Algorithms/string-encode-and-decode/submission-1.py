class Solution:
    lengths = []
    def encode(self, strs: List[str]) -> str:
        for s in strs:
            Solution.lengths.append(len(s))
        return "".join(strs)
    def decode(self, s: str) -> List[str]:
        res = []
        p = 0
        arr = Solution.lengths
        print(arr, s)
        for i in range(len(arr)):
            res.append(s[p:p+arr[i]] if arr[i] != 0 else "")
            p += arr[i]
        Solution.lengths = []
        return res
        