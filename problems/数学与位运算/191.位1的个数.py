#!/usr/bin/env python3
"""
191. 位1的个数
"""
def hamming_weight(n: int) -> int:
    count = 0
    while n:
        n &= n - 1
        count += 1
    return count

if __name__ == "__main__":
    # 测试用例
    print(hamming_weight(11))  # 预期: 3  (二进制: 1011)
    print(hamming_weight(128))  # 预期: 1  (二进制: 10000000)
    print(hamming_weight(2147483647))  # 预期: 31 (二进制: 31个1)
    print(hamming_weight(0))  # 预期: 0
