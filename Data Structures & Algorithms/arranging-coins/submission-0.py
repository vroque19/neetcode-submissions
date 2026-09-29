class Solution:
    def arrangeCoins(self, n: int) -> int:
        # the staircase has k row
        # the ith row has i coins
        # return the number of complete rows
        """
        for each row add subtract that number of coins from n
        """
        row = 1
        complete = 0
        while n > 0:
            n -= row
            if n >= 0:
                complete += 1
            row += 1
        return complete

            