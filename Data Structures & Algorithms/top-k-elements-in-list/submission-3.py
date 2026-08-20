from collections import defaultdict
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        hmap = defaultdict(lambda: 0) # create frequency map
        ans = []
        for i in range(len(nums)):
            hmap[nums[i]] += 1
        keys = list(hmap.keys())
        freq = list(hmap.values())
        sorted_freq = sorted(freq, reverse=True)
        # used_idx = []/
        for i in range(k):
            idx = freq.index(sorted_freq[i])
            freq[idx] = 0 # get rid of specific frequency after using it
            ans.append(keys[idx])
            
        return ans