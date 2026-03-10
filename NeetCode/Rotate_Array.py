def rotate(nums: list[int], k: int) -> list[int]:
    for i in range(k):
        n = nums.pop(0)
        nums.append(n)
    return nums
