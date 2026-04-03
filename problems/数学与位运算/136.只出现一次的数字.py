#!/usr/bin/env python3
"""
136. 只出现一次的数字
"""
def single_number(nums: list[int]) -> int:
    result = 0
    for num in nums:
        result ^= num
    return result

if __name__ == "__main__":
    # 测试用例
    print(single_number([2, 2, 1]))  # 预期: 1
    print(single_number([4, 1, 2, 1, 2]))  # 预期: 4
    print(single_number([1]))  # 预期: 1
