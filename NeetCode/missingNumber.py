class Solution:
    def missingNumber(self, nums: list[int]) -> int:
        i = 0
        len_nums = len(nums)
        for i in range(len_nums + 1):
            if i not in nums:
                return i
            i += 1
        return -1
