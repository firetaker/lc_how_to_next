#!/usr/bin/env python3
"""
503. 下一个更大元素 II
"""
def next_greater_elements(nums: list[int]) -> list[int]:
    n = len(nums)
    result = [-1] * n
    stack = []
    for i in range(2 * n):
        while stack and nums[stack[-1]] < nums[i % n]:
            result[stack.pop()] = nums[i % n]
        if i < n:
            stack.append(i)
    return result

if __name__ == "__main__":
    # 测试用例
    print(next_greater_elements([1, 2, 1]))
    # 预期: [2, -1, 2]
    print(next_greater_elements([1, 2, 3, 4, 3]))
    # 预期: [2, 3, 4, -1, 4]
    print(next_greater_elements([5, 4, 3, 2, 1]))
    # 预期: [-1, 5, 5, 5, 5]
