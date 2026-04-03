#!/usr/bin/env python3
"""
172. 阶乘后的零
"""
def trailing_zeroes(n: int) -> int:
    count = 0
    while n:
        n //= 5
        count += n
    return count

if __name__ == "__main__":
    # 测试用例
    print(trailing_zeroes(3))   # 预期: 0
    print(trailing_zeroes(5))   # 预期: 1
    print(trailing_zeroes(30))  # 预期: 7
    print(trailing_zeroes(0))   # 预期: 0
