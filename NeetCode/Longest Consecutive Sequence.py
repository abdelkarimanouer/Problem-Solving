class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0
        l = len(nums)
        nums.sort()
        longest = []
        c = 1
        for i in range(l - 1):
            if nums[i] == nums[i + 1]:
                continue
            if nums[i + 1] - nums[i] == 1:
                c += 1
            else:
                longest.append(c)
                c = 1
        longest.append(c)
        return max(longest)
