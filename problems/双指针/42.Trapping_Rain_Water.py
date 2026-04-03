#!/usr/bin/env python3
"""
42. 接雨水 (Trapping Rain Water)

题目: 给定 n 个非负整数表示宽度为 1 的条形图，计算下雨后能接多少雨水。

算法: 相向双指针 + 前后缀分解
      - 维护 left_max 和 right_max 分别记录左右两侧的最大高度
      - 从低的一端向中间推进
      - 每个位置的水量 = min(左侧最高, 右侧最高) - 当前高度
      - 时间复杂度 O(n)，空间复杂度 O(1)
时间复杂度: O(n)
空间复杂度: O(1)
"""

def trap(height: list[int]) -> int:
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
    # 测试用例1: 标准情况
    result = trap([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1])
    print(f"[0,1,0,2,1,0,1,3,2,1,2,1] -> {result}")  # 预期: 6

    # 测试用例2: 简单情况
    result = trap([4, 2, 0, 3, 2, 5])
    print(f"[4,2,0,3,2,5] -> {result}")  # 预期: 9

    # 测试用例3: 空数组
    result = trap([])
    print(f"[] -> {result}")  # 预期: 0
