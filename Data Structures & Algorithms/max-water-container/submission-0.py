class Solution:
    def maxArea(self, heights: List[int]) -> int:
        max_area = 0
        for i in range(len(heights)):
            for j in range(i, len(heights)):
                area = (j-i)*min(heights[i], heights[j])
                max_area = max(area, max_area)
        return max_area