class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        i = 0
        while i < len(nums) - 1:
            sum = nums[i]
            j = i + 1
            while j < len(nums):
                sum += nums[j]
                if sum == target:
                    return [i, j]
                else:
                    sum -= nums[j]
                j += 1
            i += 1
        return []
