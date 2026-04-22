class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        my_dict = defaultdict(list)
        for s in strs:
            my_dict[tuple(sorted(s))].append(s)
        return list(my_dict.values())
