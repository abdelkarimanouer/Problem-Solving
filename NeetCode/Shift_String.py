def shift_string(s: str, k: int) -> str:
    new_c = ''
    rs = ''
    for c in s:
        if c.isalpha():
            if c.islower():
                new_c = chr((ord(c) - ord('a') + k) % 26 + ord('a'))
            elif c.isupper():
                new_c = chr((ord(c) - ord('A') + k) % 26 + ord('A'))
        else:
            new_c = c
        rs += new_c
    return rs
