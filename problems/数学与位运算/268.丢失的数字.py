#!/usr/bin/env python3
"""
268. 丢失的数字
"""
def missing_number(nums: list[int]) -> int:
    result = len(nums)
    for i, num in enumerate(nums):
        result ^= i ^ num
    return result

if __name__ == "__main__":
    # 测试用例
    print(missing_number([3, 0, 1]))  # 预期: 2
    print(missing_number([0, 1]))  # 预期: 2
    print(missing_number([9, 6, 4, 2, 3, 5, 7, 0, 1]))  # 预期: 8
