from collections import defaultdict

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # hashmap to store num: index
        hmap = defaultdict()
        for i in range(len(nums)):
            print(hmap)
            if target - nums[i] in hmap and i != hmap[target - nums[i]]:
                return[hmap[target - nums[i]], i]
            hmap[nums[i]] = i
