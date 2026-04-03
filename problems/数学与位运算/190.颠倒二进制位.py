#!/usr/bin/env python3
"""
190. 颠倒二进制位
"""
def reverse_bits(n: int) -> int:
    result = 0
    for i in range(32):
        result = (result << 1) | (n & 1)
        n >>= 1
    return result

if __name__ == "__main__":
    # 测试用例
    print(reverse_bits(43261596))  # 预期: 964176192
    print(reverse_bits(4294967293))  # 预期: 3221225472
    print(reverse_bits(0))  # 预期: 0
    print(reverse_bits(1))  # 预期: 2147483648
