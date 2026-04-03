#!/usr/bin/env python3
"""
LeetCode #1: 两数之和
题目: 给定一个整数数组 nums 和一个目标值 target，请你在数组中找出和为目标值的两个整数。
解法: 哈希表 - 遍历时用字典记录已遍历元素及其索引，对于当前元素 nums[i]，
      查找 target - nums[i] 是否在字典中。时间 O(n)，空间 O(n)。
"""


def two_sum(nums: list[int], target: int) -> list[int]:
    """
    哈希表法: 维护一个字典，将已遍历的元素及其索引存入。
    对于每个元素，检查 target - nums[i] 是否在字典中。
    """
    index_map = {}  # val -> index
    for i, num in enumerate(nums):
        complement = target - num
        if complement in index_map:
            return [index_map[complement], i]
        index_map[num] = i
    return []


if __name__ == "__main__":
    # 测试用例
    print(two_sum([2, 7, 11, 15], 9))   # [0, 1]
    print(two_sum([3, 2, 4], 6))        # [1, 2]
    print(two_sum([3, 3], 6))           # [0, 1]
