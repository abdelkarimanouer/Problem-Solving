class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        t = []
        for i in range(0, rowIndex + 1):
            l = [1]
            if t:
                for j in range(len(t[-1]) - 1):
                    l.append(t[-1][j] + t[-1][j+1])
                l.append(1)
            t.append(l)
        return t[rowIndex]
