#!/usr/bin/env python3
"""
15. 三数之和 (3Sum)

题目: 给你一个整数数组 nums，判断是否存在三元组 [nums[i], nums[j], nums[k]]
      满足 i != j、i != k 且 j != k，同时满足 nums[i] + nums[j] + nums[k] == 0。
      返回所有满足条件的三元组（不可重复）。

算法: 排序 + 双指针
      - 先对数组排序
      - 固定指针 i，然后在 i+1 到 n-1 之间用双指针 left, right
      - 若三数之和为 0，记录并移动指针去重
      - 时间复杂度 O(n²)，空间复杂度 O(1)
时间复杂度: O(n²)
空间复杂度: O(1)
"""

def three_sum(nums: list[int]) -> list[list[int]]:
    nums.sort()
    result = []
    for i in range(len(nums) - 2):
        if i > 0 and nums[i] == nums[i - 1]:
            continue
        left, right = i + 1, len(nums) - 1
        while left < right:
            s = nums[i] + nums[left] + nums[right]
            if s < 0:
                left += 1
            elif s > 0:
                right -= 1
            else:
                result.append([nums[i], nums[left], nums[right]])
                left += 1
                right -= 1
                while left < right and nums[left] == nums[left - 1]:
                    left += 1
                while left < right and nums[right] == nums[right + 1]:
                    right -= 1
    return result


if __name__ == "__main__":
    # 测试用例1: 标准情况
    result = three_sum([-1, 0, 1, 2, -1, -4])
    print(f"[-1,0,1,2,-1,-4] -> {result}")  # 预期: [[-1,-1,2],[-1,0,1]]

    # 测试用例2: 无解情况
    result = three_sum([0, 1, 1])
    print(f"[0,1,1] -> {result}")  # 预期: []

    # 测试用例3: 全零情况
    result = three_sum([0, 0, 0])
    print(f"[0,0,0] -> {result}")  # 预期: [[0,0,0]]
