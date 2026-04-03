#!/usr/bin/env python3
"""
434. 字符串中的单词数
"""


def count_segments(s: str) -> int:
    return len([w for w in s.split() if w])


if __name__ == "__main__":
    # 测试用例
    print(count_segments("Hello, my name is John"))  # 预期: 5
    print(count_segments(""))                       # 预期: 0
    print(count_segments("    "))                  # 预期: 0
    print(count_segments("a"))                     # 预期: 1
