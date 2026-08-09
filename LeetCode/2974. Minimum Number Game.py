import heapq as h


class Solution:
    def numberGame(self, nums: List[int]) -> List[int]:
        h.heapify(nums)

        arr = []
        while nums:
            alice = h.heappop(nums)
            bob = h.heappop(nums)

            arr.append(bob)
            arr.append(alice)

        return arr
