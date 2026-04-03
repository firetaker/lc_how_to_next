#!/usr/bin/env python3
"""
28. 找出字符串中第一个匹配项的下标
"""


def str_str(haystack: str, needle: str) -> int:
    if not needle:
        return 0
    n, m = len(haystack), len(needle)
    if n < m:
        return -1

    # KMP 构建前缀表
    lps = [0] * m
    length = 0
    i = 1
    while i < m:
        if needle[i] == needle[length]:
            length += 1
            lps[i] = length
            i += 1
        else:
            if length != 0:
                length = lps[length - 1]
            else:
                lps[i] = 0
                i += 1

    # KMP 搜索
    i = j = 0
    while i < n:
        if haystack[i] == needle[j]:
            i += 1
            j += 1
            if j == m:
                return i - j
        else:
            if j != 0:
                j = lps[j - 1]
            else:
                i += 1
    return -1


if __name__ == "__main__":
    # 测试用例
    print(str_str("sadbutsad", "sad"))  # 预期: 0
    print(str_str("leetcode", "leeto"))  # 预期: -1
    print(str_str("aabaabaafa", "aabaaf"))  # 预期: 3
