#!/usr/bin/env python3
"""
84. 柱状图中最大的矩形
算法: 单调递增栈
时间复杂度: O(n)
空间复杂度: O(n)
"""
def largest_rectangle_area(heights: list[int]) -> int:
    stack = []
    max_area = 0
    for i, h in enumerate(heights + [0]):
        while stack and heights[stack[-1]] > h:
            height = heights[stack.pop()]
            width = i if not stack else i - stack[-1] - 1
            max_area = max(max_area, height * width)
        stack.append(i)
    return max_area


if __name__ == "__main__":
    print(largest_rectangle_area([2, 1, 5, 6, 2, 3]))  # 预期: 10
    print(largest_rectangle_area([2, 4]))               # 预期: 4
    print(largest_rectangle_area([1]))                  # 预期: 1
