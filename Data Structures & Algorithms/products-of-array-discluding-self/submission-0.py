class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        res = []
        idx = 0
        for i in range(len(nums)):
            curr_product = 1
            for j in range(len(nums)):
                if j == i:
                    continue
                curr_product *= nums[j] 
            res.append(curr_product)
        return res