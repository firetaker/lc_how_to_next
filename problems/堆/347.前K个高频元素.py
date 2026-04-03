#!/usr/bin/env python3
"""
347. 前 K 个高频元素
"""
import heapq
from collections import Counter

def top_k_frequent(nums: list[int], k: int) -> list[int]:
    count = Counter(nums)
    return [item[0] for item in heapq.nlargest(k, count.items(), key=lambda x: x[1])]

if __name__ == "__main__":
    # 测试用例
    print(top_k_frequent([1, 1, 1, 2, 2, 3], 2))  # 预期: [1, 2]
    print(top_k_frequent([1], 1))  # 预期: [1]
    print(top_k_frequent([4, 4, 4, 6, 6, 6, 6, 1, 2], 2))  # 预期: [6, 4]
