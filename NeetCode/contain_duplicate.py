def hasDuplicate(self, nums: list[int]) -> bool:
    my_set = set()
    for x in nums:
        if x in my_set:
            return True
        else:
            my_set.add(x)
    return False
