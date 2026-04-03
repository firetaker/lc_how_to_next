#!/usr/bin/env python3
"""
169. 多数元素
"""
def majority_element(nums: list[int]) -> int:
    count = 0
    candidate = None
    for num in nums:
        if count == 0:
            candidate = num
        count += (1 if num == candidate else -1)
    return candidate

if __name__ == "__main__":
    # 测试用例
    print(majority_element([3, 2, 3]))  # 预期: 3
    print(majority_element([2, 2, 1, 1, 1, 2, 2]))  # 预期: 2
    print(majority_element([1]))  # 预期: 1
