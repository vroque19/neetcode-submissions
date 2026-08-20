class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        def getDist(x: int, y: int) -> float:
            return math.sqrt((x*x)+(y*y))
        minHeap = []
        for point in points:
            x = point[0]
            y = point[1]
            curr_dist = getDist(x, y)
            minHeap.append([curr_dist, x, y])
        heapq.heapify(minHeap)
        print(minHeap)
        res = []
        i = 0
        while i < k:
            dist, x, y = (heapq.heappop(minHeap))
            res.append([x, y])
            i+= 1
        return res
        