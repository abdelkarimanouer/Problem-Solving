class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        l = []
        if m > 0:
            l += nums1[:m]
        if n > 0:
            l += nums2[:n]
        nums1.clear()
        nums1 += l
        nums1.sort()
