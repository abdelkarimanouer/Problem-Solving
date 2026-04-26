class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        d = dict()
        l = []
        c = 0
        for n in nums:
            d[n] = d.get(n, 0) + 1

        sorted_keys = sorted(d, key=lambda x: d[x], reverse=True)
        return sorted_keys[:k]
