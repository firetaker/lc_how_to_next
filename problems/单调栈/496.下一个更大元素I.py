#!/usr/bin/env python3
"""
496. 下一个更大元素 I
"""
def next_greater_element(nums1: list[int], nums2: list[int]) -> list[int]:
    stack = []
    next_greater = {}
    for num in nums2:
        while stack and stack[-1] < num:
            next_greater[stack.pop()] = num
        stack.append(num)
    return [next_greater.get(num, -1) for num in nums1]

if __name__ == "__main__":
    # 测试用例
    print(next_greater_element([4, 1, 2], [1, 3, 4, 2]))
    # 预期: [-1, 3, -1]
    print(next_greater_element([2, 4], [1, 2, 3, 4]))
    # 预期: [3, -1]
    print(next_greater_element([1, 3, 5, 2, 4], [6, 5, 4, 3, 2, 1, 7]))
    # 预期: [7, 7, 7, 7, 7]
