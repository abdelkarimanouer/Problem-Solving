def convert_base(num: str, b1: int, b2: int) -> str:
    n = int(num, b1)

    if n == 0:
        return '0'

    digits = "0123456789abcdefghijklmnopqrstuvwxyz"
    rs = ''
    while n > 0:
        rs = digits[n % b2] + rs
        n //= b2
    return rs
