#!/usr/bin/env python3
"""
338. 比特位计数
"""
def count_bits(n: int) -> list[int]:
    dp = [0] * (n + 1)
    for i in range(1, n + 1):
        dp[i] = dp[i >> 1] + (i & 1)
    return dp

if __name__ == "__main__":
    # 测试用例
    print(count_bits(2))   # 预期: [0, 1, 1]
    print(count_bits(5))   # 预期: [0, 1, 1, 2, 1, 2]
    print(count_bits(0))   # 预期: [0]
    print(count_bits(1))   # 预期: [0, 1]
