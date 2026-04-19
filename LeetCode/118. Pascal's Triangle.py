class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        t = []
        for i in range(1, numRows + 1):
            l = [1]
            if t:
                for j in range(len(t[-1]) - 1):
                    l.append(t[-1][j] + t[-1][j+1])
                l.append(1)
            t.append(l)
        return t
