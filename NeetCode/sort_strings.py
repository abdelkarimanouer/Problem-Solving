def sort_strings(strs: list[str]) -> list[str]:
    strs = sorted(strs, key=lambda s: (len(s), s.lower(),
                                       sum(s.count(v) for v in "aeoiuAEOIU"),
                                       strs.index(s)))
    return strs
