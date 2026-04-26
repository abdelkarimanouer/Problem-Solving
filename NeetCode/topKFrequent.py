class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        d = dict()
        l = []
        for n in nums:
            if n not in d.keys():
                d[n] = nums.count(n)
        s_d = dict(sorted(d.items(), key=lambda item: item[1], reverse=True))
        print(s_d)
        for i in range(k):
            l.append(list(s_d.keys())[i])
        return l
