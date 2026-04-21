from functools import lru_cache

class Solution:
    @lru_cache
    def get_result(self, n: int) -> int:
        if n <= 1:
            return n
        return self.get_result(n - 1) + self.get_result(n - 2)

    def climbStairs(self, n: int) -> int:
        rs = self.get_result(n + 1)
        return rs
