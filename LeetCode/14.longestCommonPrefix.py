class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        strs.sort()
        i = 0
        rs = ""
        length = len(strs)
        while i < len(strs[0]):
            if strs[0][i] == strs[length - 1][i]:
                rs += strs[0][i]
            else:
                break
            i += 1
        return rs 
