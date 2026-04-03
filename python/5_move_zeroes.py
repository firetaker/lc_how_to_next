#!/usr/bin/env python3
"""
LeetCode #283: 移动零
题目: 给定一个数组，将所有 0 移动到数组末尾，同时保持非零元素的相对顺序。
解法: 双指针 - left 指向已处理区域的最后一个位置（所有非零元素），
      right 遍历数组。遇到非零元素时与 left 位置交换，left 右移。
      时间 O(n)，空间 O(1)。
"""


def move_zeroes(nums: list[int]) -> None:
    """
    双指针交换: left 左侧（不含 left）都是非零元素，
    right 从左向右扫描，将非零元素与 left 交换。
    """
    left = 0
    for right in range(len(nums)):
        if nums[right] != 0:
            nums[left], nums[right] = nums[right], nums[left]
            left += 1


if __name__ == "__main__":
    # 测试用例
    arr = [0, 1, 0, 3, 12]
    move_zeroes(arr)
    print(arr)  # [1, 3, 12, 0, 0]
