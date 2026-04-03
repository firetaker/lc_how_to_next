#!/usr/bin/env python3
"""
LeetCode #11: 盛最多水的容器
题目: 给定一个 height 数组，每条垂线宽度为1，求能盛放的最大水量。
解法: 相向双指针 - 左右指针向中间移动，每次移动较短的那条边，
      因为水量由较短边决定。每次更新最大面积。
      时间 O(n)，空间 O(1)。
"""


def max_area(height: list[int]) -> int:
    """
    相向双指针: left=0, right=n-1，向中间移动。
    面积 = min(height[left], height[right]) * (right - left)
    每次移动较短边，保留较大边以期望获得更大面积。
    """
    left, right = 0, len(height) - 1
    max_water = 0
    while left < right:
        h = min(height[left], height[right])
        w = right - left
        max_water = max(max_water, h * w)
        # 移动较短边
        if height[left] < height[right]:
            left += 1
        else:
            right -= 1
    return max_water


if __name__ == "__main__":
    # 测试用例
    print(max_area([1, 8, 6, 2, 5, 4, 8, 3, 7]))  # 49
    print(max_area([1, 1]))  # 1
