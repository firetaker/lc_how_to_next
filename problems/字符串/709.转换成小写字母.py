#!/usr/bin/env python3
"""
709. 转换成小写字母
"""


def to_lower_case(s: str) -> str:
    return s.lower()


if __name__ == "__main__":
    # 测试用例
    print(to_lower_case("Hello"))    # 预期: "hello"
    print(to_lower_case("here"))     # 预期: "here"
    print(to_lower_case("LOVELY"))   # 预期: "lovely"
