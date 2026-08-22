class Solution:
    def addDigits(self, num: int) -> int:
        if num >= 0 and num <= 9:
            return num
        n_str = str(num)
        nums = [int(n) for n in n_str]
        rs = sum(nums)
        return self.addDigits(rs)
