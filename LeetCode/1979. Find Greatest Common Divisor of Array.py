class Solution:
    def findGCD(self, nums: List[int]) -> int:
        small_num = min(nums)
        large_num = max(nums)
        g_c_d = 0
        for i in range(1, small_num + 1):
            if (small_num % i == 0) and (large_num % i == 0):
                g_c_d = i
        return g_c_d
