class Solution:
    def climbStairs(self, n: int) -> int:
        n += 1
        a = 0
        b = 1

        if n == 0:
            return 0
        elif n == 1:
            return b
        else:
            for i in range(1, n):
                b, a = a + b, b
        return b
 
