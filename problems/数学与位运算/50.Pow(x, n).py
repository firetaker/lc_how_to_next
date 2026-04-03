#!/usr/bin/env python3
"""
50. Pow(x, n)
"""
def my_pow(x: float, n: int) -> float:
    if n < 0:
        x = 1 / x
        n = -n
    result = 1.0
    cur = x
    while n:
        if n % 2 == 1:
            result *= cur
        cur *= cur
        n //= 2
    return result

if __name__ == "__main__":
    # 测试用例
    print(my_pow(2.00000, 10))   # 预期: 1024.0
    print(my_pow(2.10000, 3))    # 预期: 9.261
    print(my_pow(2.00000, -2))   # 预期: 0.25
    print(my_pow(0.00000, 1))    # 预期: 0.0
