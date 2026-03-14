class Solution:
    def reverseBits(self, n: int) -> int:
        b = '{:032b}'.format(n)
        b = b[::-1]
        b = b.replace('b0', '')
        n = int(b, 2)
        return n
