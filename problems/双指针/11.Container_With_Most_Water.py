#!/usr/bin/env python3
"""
11. 盛最多水的容器 (Container With Most Water)

题目: 给定 n 个非负整数 a1, a2, ..., an，每个数代表一条垂直线段，位置 i 的线段高度为 ai。
      两线段 i 和 j 之间的面积定义为 min(ai, aj) * |j - i|。
      找出其中的两条线段，使它们组成的容器能装最多的水。

算法: 相向双指针
      - 左指针指向起始位置，右指针指向结束位置
      - 每次移动较短边的指针（因为移动较长边只会减少宽度）
      - 时间复杂度 O(n)，空间复杂度 O(1)
时间复杂度: O(n)
空间复杂度: O(1)
"""

def max_area(height: list[int]) -> int:
    left, right = 0, len(height) - 1
    max_water = 0
    while left < right:
        width = right - left
        h = min(height[left], height[right])
        max_water = max(max_water, width * h)
        if height[left] < height[right]:
            left += 1
        else:
            right -= 1
    return max_water


if __name__ == "__main__":
    # 测试用例1: 标准情况
    result = max_area([1, 8, 6, 2, 5, 4, 8, 3, 7])
    print(f"height = [1, 8, 6, 2, 5, 4, 8, 3, 7] -> {result}")  # 预期: 49

    # 测试用例2: 最小情况
    result = max_area([1, 1])
    print(f"height = [1, 1] -> {result}")  # 预期: 1

    # 测试用例3: 对称情况
    result = max_area([4, 3, 2, 1, 4])
    print(f"height = [4, 3, 2, 1, 4] -> {result}")  # 预期: 16
