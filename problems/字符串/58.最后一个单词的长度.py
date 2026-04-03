#!/usr/bin/env python3
"""
58. 最后一个单词的长度
"""


def length_of_last_word(s: str) -> int:
    words = s.strip().split()
    return len(words[-1]) if words else 0


if __name__ == "__main__":
    # 测试用例
    print(length_of_last_word("Hello World"))      # 预期: 5
    print(length_of_last_word("   fly me   to   the moon  "))  # 预期: 4
    print(length_of_last_word("a"))               # 预期: 1
