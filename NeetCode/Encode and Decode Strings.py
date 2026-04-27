class Solution:

    def encode(self, strs: List[str]) -> str:
        rs = ""
        l = len(strs)
        if not strs:
            return "%__%#empty_list#%__%"
        for i in range(l):
            if not strs[i]:
                rs += "%__%#space#%__%"
            else:
                rs +=  strs[i]
            if i <  l - 1:
                rs += '%__%##%__%'
        return rs
    def decode(self, s: str) -> List[str]:
        if s == "%__%#empty_list#%__%":
            return []
        l = s.split('%__%##%__%')
        for i in range(len(l)):
            if l[i] == "%__%#space#%__%":
                l[i] = ""
        return l
