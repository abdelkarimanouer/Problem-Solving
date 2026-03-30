class Solution:
    def romanToInt(self, s: str) -> int:
        r = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        rs = 0
        i = 0
        l_s = len(s)
        while i < l_s:
            if i+1 < l_s:
                if s[i] == 'I' and s[i+1] == 'V':
                    rs += 4
                    i += 2
                elif s[i] == 'I' and s[i+1] == 'X':
                    rs += 9
                    i += 2
                elif s[i] == 'X' and s[i+1] == 'L':
                    rs += 40
                    i += 2
                elif s[i] == 'X' and s[i+1] == 'C':
                    rs += 90
                    i += 2
                elif s[i] == 'C' and s[i+1] == 'D':
                    rs += 400
                    i += 2
                elif s[i] == 'C' and s[i+1] == 'M':
                    rs += 900
                    i += 2
                else:
                    rs += r[s[i]]
                    i += 1
            else:
                rs += r[s[i]]
                i += 1
        return rs
