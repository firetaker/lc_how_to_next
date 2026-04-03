#!/usr/bin/env python3
"""
520. 检测大写字母
"""


def detect_capital_use(word: str) -> bool:
    return word.isupper() or word.islower() or (word[0].isupper() and word[1:].islower())


if __name__ == "__main__":
    # 测试用例
    print(detect_capital_use("USA"))      # 预期: True
    print(detect_capital_use("FlaG"))     # 预期: False
    print(detect_capital_use("Google"))   # 预期: True
    print(detect_capital_use("leetcode")) # 预期: True
