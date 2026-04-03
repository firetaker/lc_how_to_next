#!/usr/bin/env python3
"""
137. 只出现一次的数字 II
"""
def single_number_ii(nums: list[int]) -> int:
    seen_once = seen_twice = 0
    for num in nums:
        seen_once = (seen_once ^ num) & ~seen_twice
        seen_twice = (seen_twice ^ num) & ~seen_once
    return seen_once

if __name__ == "__main__":
    # 测试用例
    print(single_number_ii([2, 2, 3, 2]))  # 预期: 3
    print(single_number_ii([0, 1, 0, 1, 0, 1, 99]))  # 预期: 99
    print(single_number_ii([-2, -2, -1, -2, -1, -1]))  # 预期: -1
