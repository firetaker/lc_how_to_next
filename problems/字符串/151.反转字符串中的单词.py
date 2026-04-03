#!/usr/bin/env python3
"""
151. 反转字符串中的单词
"""


def reverse_words(s: str) -> str:
    return ' '.join(s.strip().split()[::-1])


if __name__ == "__main__":
    # 测试用例
    print(reverse_words("the sky is blue"))      # 预期: "blue is sky the"
    print(reverse_words("  hello world  "))     # 预期: "world hello"
    print(reverse_words("a good   example"))    # 预期: "example good a"
