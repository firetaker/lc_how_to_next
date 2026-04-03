#!/usr/bin/env python3
"""
215. 数组中的第K个最大元素
"""
import heapq

def find_kth_largest(nums: list[int], k: int) -> int:
    return heapq.nlargest(k, nums)[-1]

if __name__ == "__main__":
    # 测试用例
    print(find_kth_largest([3, 2, 1, 5, 6, 4], 2))  # 预期: 5
    print(find_kth_largest([3, 2, 3, 1, 2, 4, 5, 5, 6], 4))  # 预期: 4
    print(find_kth_largest([1], 1))  # 预期: 1
