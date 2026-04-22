class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        i = 0
        ls = []
        l = len(words)
        while i < len(words):
            for s in words:
                if s == words[i]:
                    continue
                if words[i] in s:
                    if words[i] not in ls:
                        ls.append(words[i])
                    else:
                        continue
            i += 1
        return ls
