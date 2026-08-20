from collections import defaultdict
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        p1 = 0
        hmap = defaultdict(lambda: 0)
        longest = 0
        for i in range(len(s)):
            hmap[s[i]] += 1
            while hmap[s[i]] > 1:
                hmap[s[p1]] -= 1
                p1 += 1
            longest = max(longest, i - p1 + 1)
        return longest

            

        
        
