class Solution:
    def maxProduct(self, n: int) -> int:
        n = str(n)
        digits = [int(c) for c in n]
        max_digit = max(digits)
        if digits.count(max_digit) >= 2:
            return max_digit * max_digit
        digits.remove(max_digit)
        second_max_digit = max(digits)
        return max_digit * second_max_digit
