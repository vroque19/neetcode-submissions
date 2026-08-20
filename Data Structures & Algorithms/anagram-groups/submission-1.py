class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = []
        vals = defaultdict(lambda: list()) # value and length
        
        for s in strs:
            vals["".join(sorted(s))].append(s)
        print(vals)
        for v in vals.values():
            res.append(v)

        return res