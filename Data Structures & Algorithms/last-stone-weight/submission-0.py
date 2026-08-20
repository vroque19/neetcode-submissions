class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        if len(stones) == 0:
            return 0
        if len(stones) == 1:
            return stones[0]
        stones = sorted(stones)
        new_stone = stones[len(stones)-1] - stones[len(stones)-2]
        stones = stones[:len(stones)-2]
        stones.append(new_stone)
        return self.lastStoneWeight(stones)