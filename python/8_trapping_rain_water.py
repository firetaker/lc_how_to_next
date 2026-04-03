#!/usr/bin/env python3
"""
LeetCode #42: 接雨水
题目: 给定 n 个非负整数表示的高度图，计算能接多少雨水。
解法: 前后缀分解 / 相向双指针 - 预处理每个位置左右最高墙，
      第 i 位能接的雨水 = max(0, min(left_max[i], right_max[i]) - height[i])。
      优化: 相向双指针只需 O(1) 额外空间。
      时间 O(n)，空间 O(n) 或 O(1)（双指针优化）。
"""


def trap(height: list[int]) -> int:
    """
    前后缀分解: left_max[i] 表示 [0..i] 的最高墙，
    right_max[i] 表示 [i..n-1] 的最高墙。
    """
    if not height:
        return 0
    n = len(height)
    left_max = [0] * n
    right_max = [0] * n
    left_max[0] = height[0]
    for i in range(1, n):
        left_max[i] = max(left_max[i - 1], height[i])
    right_max[n - 1] = height[n - 1]
    for i in range(n - 2, -1, -1):
        right_max[i] = max(right_max[i + 1], height[i])
    water = 0
    for i in range(n):
        water += max(0, min(left_max[i], right_max[i]) - height[i])
    return water


def trap_two_pointer(height: list[int]) -> int:
    """
    相向双指针优化: left=0, right=n-1，左右最高墙动态维护。
    每次移动较小边对应的指针，更新答案。
    """
    if not height:
        return 0
    left, right = 0, len(height) - 1
    left_max, right_max = 0, 0
    water = 0
    while left < right:
        if height[left] < height[right]:
            if height[left] >= left_max:
                left_max = height[left]
            else:
                water += left_max - height[left]
            left += 1
        else:
            if height[right] >= right_max:
                right_max = height[right]
            else:
                water += right_max - height[right]
            right -= 1
    return water


if __name__ == "__main__":
    # 测试用例
    print(trap([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]))  # 6
    print(trap_two_pointer([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]))  # 6
