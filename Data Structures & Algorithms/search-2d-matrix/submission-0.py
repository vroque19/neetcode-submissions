class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        ROWS, COLS = len(matrix), len(matrix[0])

        t, b = 0, ROWS - 1
        while t <= b:
            row = (t+b) // 2
            if target > matrix[row][-1]:
                t = row + 1
            elif target < matrix[row][0]:
                b = row - 1
            else:
                break
  
        if not (t <= b):
            return False
        l, r = 0, COLS - 1
        row = (t + b) // 2
        while l <= r:
            mid = (l + r) // 2
            if target > matrix[row][mid]:
                l = mid + 1
            elif target < matrix[row][mid]:
                r = mid - 1
            else:
                return True
        return False
        

                    
                

                