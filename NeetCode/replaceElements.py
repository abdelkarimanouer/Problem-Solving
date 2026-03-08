class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        i = 0
        while i < len(arr) - 1:
            m = max(arr[i + 1:])
            arr[i] = m
            i += 1

        arr[i] = -1
        return arr
