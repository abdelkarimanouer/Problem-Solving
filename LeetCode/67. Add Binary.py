class Solution:
    def addBinary(self, a: str, b: str) -> str:
        n1 = int(a, 2)
        n2 = int(b, 2)
        rs = n1 + n2
        rs = bin(rs).replace('0b', '')
        return rs
