class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s = s[::-1]
        l = 0
        for c in s:
            if c != ' ':
                l += 1
            elif c == ' ' and l > 0:
                return l
            else:
                continue
        return l
