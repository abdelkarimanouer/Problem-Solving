def convert_case_string(s: str):
    new_c = ''
    rs = ''
    for c in s:
        if c.isalpha():
            if c.islower():
                new_c = chr(ord(c) - 32)
            elif c.isupper():
                new_c = chr(ord(c) + 32)
        elif c.isspace():
            new_c = ' '
        else:
            new_c = ''
        rs += new_c
    return rs
