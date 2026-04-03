#!/usr/bin/env python3
"""
75. 颜色分类 (Sort Colors)

题目: 给定一个包含红色、白色和蓝色，共 n 个元素的数组 nums，
      原地对它们进行排序，使得相同颜色的元素相邻，并按红色、白色、蓝色的顺序排列。
      本题中，使用整数 0、1 和 2 分别表示红色、白色和蓝色。

算法: 荷兰国旗三路指针
      - left 指针左侧全是 0（红色）
      - right 指针右侧全是 2（蓝色）
      - cur 指针遍历数组，遇到 0 或 2 就交换
      - 时间复杂度 O(n)，空间复杂度 O(1)
时间复杂度: O(n)
空间复杂度: O(1)
"""

def sort_colors(nums: list[int]) -> None:
    left, cur, right = 0, 0, len(nums) - 1
    while cur <= right:
        if nums[cur] == 0:
            nums[left], nums[cur] = nums[cur], nums[left]
            left += 1
            cur += 1
        elif nums[cur] == 2:
            nums[cur], nums[right] = nums[right], nums[cur]
            right -= 1
        else:
            cur += 1


if __name__ == "__main__":
    # 测试用例1: 标准情况
    nums1 = [2, 0, 2, 1, 1, 0]
    sort_colors(nums1)
    print(f"[2,0,2,1,1,0] -> {nums1}")  # 预期: [0, 0, 1, 1, 2, 2]

    # 测试用例2: 简单情况
    nums2 = [2, 0, 1]
    sort_colors(nums2)
    print(f"[2,0,1] -> {nums2}")  # 预期: [0, 1, 2]

    # 测试用例3: 全相同颜色
    nums3 = [1, 1, 1]
    sort_colors(nums3)
    print(f"[1,1,1] -> {nums3}")  # 预期: [1, 1, 1]
