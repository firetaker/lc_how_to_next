#!/usr/bin/env python3
"""
186. 翻转字符串里的单词 II
"""


def reverse_words(s: list[str]) -> None:
    s.reverse()
    i = 0
    for j in range(len(s) + 1):
        if j == len(s) or s[j] == ' ':
            l, r = i, j - 1
            while l < r:
                s[l], s[r] = s[r], s[l]
                l += 1
                r -= 1
            i = j + 1


if __name__ == "__main__":
    # 测试用例
    s1 = list("the sky is blue")
    reverse_words(s1)
    print(''.join(s1))  # 预期: "blue is sky the"

    s2 = list("  hello world  ")
    reverse_words(s2)
    print(''.join(s2))  # 预期: "world hello"
