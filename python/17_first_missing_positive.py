#!/usr/bin/env python3
"""
LeetCode #41: 缺失的第一个正数
题目: 给定未排序整数数组，找出未出现的最小正整数。要求 O(n) 时间，O(1) 空间。
解法: 索引与值匹配 - 将每个正数 num 放到索引 num-1 的位置（即 nums[num-1] = num）。
      第一遍：将数 x（1 <= x <= n）放到正确位置
      第二遍：第一个 nums[i] != i+1 的位置 i+1 即为答案
      若全匹配，则答案是 n+1。
"""


def firstMissingPositive(nums: list[int]) -> int:
    """
    索引标记法: 将 num 放到 num-1 位置，利用索引做哈希。
    第一遍：将数放到正确位置
    第二遍：找第一个不匹配的位置
    """
    n = len(nums)
    i = 0
    while i < n:
        num = nums[i]
        if 1 <= num <= n and nums[num - 1] != num:
            nums[i], nums[num - 1] = nums[num - 1], nums[i]
        else:
            i += 1
    # 找第一个不匹配的位置
    for i in range(n):
        if nums[i] != i + 1:
            return i + 1
    return n + 1


if __name__ == "__main__":
    print(firstMissingPositive([1, 2, 0]))           # 3
    print(firstMissingPositive([3, 4, -1, 1]))     # 2
    print(firstMissingPositive([7, 8, 9, 11, 12])) # 1
