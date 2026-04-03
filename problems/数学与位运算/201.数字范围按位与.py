#!/usr/bin/env python3
"""
201. 数字范围按位与
"""
def range_bitwise_and(left: int, right: int) -> int:
    shift = 0
    while left < right:
        left >>= 1
        right >>= 1
        shift += 1
    return left << shift

if __name__ == "__main__":
    # 测试用例
    print(range_bitwise_and(5, 7))   # 预期: 4
    print(range_bitwise_and(0, 0))    # 预期: 0
    print(range_bitwise_and(1, 2147483647))  # 预期: 0
    print(range_bitwise_and(16, 31))  # 预期: 16
