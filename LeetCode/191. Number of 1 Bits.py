class Solution:
    def hammingWeight(self, n: int) -> int:
        n = bin(n)
        count_one = n.count('1')
        return count_one
