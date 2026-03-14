class Solution:
    def countBits(self, n: int) -> List[int]:
        l = []
        i = 0
        while i <= n:
            b = bin(i)
            c = b.count('1')
            l.append(c)
            i += 1
        return l
