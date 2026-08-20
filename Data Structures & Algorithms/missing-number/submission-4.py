class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        # 0, 1, 3, 4, 5; s = 15, a0 = 0 an = 5 n = 6
        n = len(nums)
        an = n+1
        a0 = 0
        summ = (n/2)*(a0+an)
        return int(summ - sum(nums))
        
        
        