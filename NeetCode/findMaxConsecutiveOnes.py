class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        c = 0
        big_c = 0
        for i in range(len(nums)):
            if nums[i] == 1:
                c += 1
                if c > big_c:
                    big_c = c
            else:
                c = 0
        c = big_c
        return c
