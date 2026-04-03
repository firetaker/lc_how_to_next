#!/usr/bin/env python3
"""
LeetCode #15: 三数之和
题目: 给定一个数组，找出所有和为0的不重复三元组。
解法: 排序 + 双指针 - 先对数组排序，固定一个数 i，然后使用双指针
      left=i+1, right=n-1 找剩余两个数。需去重。
      时间 O(n^2)，空间 O(1)（不计结果空间）。
"""


def three_sum(nums: list[int]) -> list[list[int]]:
    """
    排序 + 双指针: 先排序，固定 i，再用双指针找两数之和为 -nums[i]。
    去重策略: 跳过相同的 i, left, right 值。
    """
    nums.sort()
    n = len(nums)
    result = []
    for i in range(n - 2):
        # 跳过正数（无解）
        if nums[i] > 0:
            break
        # 跳过重复的 i
        if i > 0 and nums[i] == nums[i - 1]:
            continue
        left, right = i + 1, n - 1
        while left < right:
            total = nums[i] + nums[left] + nums[right]
            if total == 0:
                result.append([nums[i], nums[left], nums[right]])
                left += 1
                right -= 1
                # 跳过重复的 left 和 right
                while left < right and nums[left] == nums[left - 1]:
                    left += 1
                while left < right and nums[right] == nums[right + 1]:
                    right -= 1
            elif total < 0:
                left += 1
            else:
                right -= 1
    return result


if __name__ == "__main__":
    # 测试用例
    print(three_sum([-1, 0, 1, 2, -1, -4]))
    # [[-1, -1, 2], [-1, 0, 1]]
