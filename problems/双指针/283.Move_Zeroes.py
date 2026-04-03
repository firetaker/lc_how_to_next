#!/usr/bin/env python3
"""
283. 移动零 (Move Zeroes)

题目: 给定一个数组 nums，将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
      必须在原地修改数组，且最少操作次数。

算法: 快慢指针
      - 慢指针 left 指向已处理区域（不含零）的最后一个位置
      - 快指针 right 遍历数组，寻找非零元素
      - 找到非零元素时与 left 位置交换，然后 left 右移
      - 时间复杂度 O(n)，空间复杂度 O(1)
时间复杂度: O(n)
空间复杂度: O(1)
"""

def move_zeroes(nums: list[int]) -> None:
    left = 0
    for right in range(len(nums)):
        if nums[right] != 0:
            nums[left], nums[right] = nums[right], nums[left]
            left += 1


if __name__ == "__main__":
    # 测试用例1: 标准情况
    nums1 = [0, 1, 0, 3, 12]
    move_zeroes(nums1)
    print(f"[0, 1, 0, 3, 12] -> {nums1}")  # 预期: [1, 3, 12, 0, 0]

    # 测试用例2: 零在前面
    nums2 = [0, 0, 1]
    move_zeroes(nums2)
    print(f"[0, 0, 1] -> {nums2}")  # 预期: [1, 0, 0]

    # 测试用例3: 全为零
    nums3 = [0, 0, 0]
    move_zeroes(nums3)
    print(f"[0, 0, 0] -> {nums3}")  # 预期: [0, 0, 0]
