class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prefix = 1
        res = [1] * (len(nums))
        for i in range(len(nums)):
            res[i] = prefix
            prefix = res[i] * nums[i]
        postfix = 1    
        for i in range(len(nums) -1, -1, -1):
            res[i] *= postfix
            postfix *= nums[i]
        print(prefix)
        print(postfix)
        return res
        