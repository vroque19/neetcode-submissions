class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums = sorted(nums)
        for i in range(len(nums)):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            p1, p2 = i+1, len(nums)-1
            while p1 < p2:
                curr_sum = nums[i] + nums[p1] + nums[p2]
                if curr_sum == 0:
                    res.append([nums[i], nums[p1], nums[p2]])
                    while p1 < p2 and nums[p1]==nums[p1+1]:
                        p1+=1
                    while p1 < p2 and nums[p2]==nums[p2-1]:
                        p2-=1
                    p1+=1
                    p2-=1
                elif curr_sum < 0:
                    p1+=1
                elif curr_sum > 0:
                    p2 -=1
        return res
            




