class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        longest_length = 0
        max_count = 0
        p1 = 0
        p2 = 0
        count = defaultdict(lambda: 0)
    
        while p2 < len(s):
            count[s[p2]] += 1
            width = len(s[p1:p2+1])
            max_c = max(count, key=count.get)
            if (width-count[max_c] <= k):
                print(count, p1, p2, width, count[max_c])
                longest_length = max(width, longest_length)
              
            else:
                count[s[p1]] -= 1
                p1 +=1

            p2 +=1
        return longest_length    
        