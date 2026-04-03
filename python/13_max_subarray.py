#!/usr/bin/env python3
"""
LeetCode #53: 最大子数组和
题目: 找出连续子数组（至少包含一个元素）的最大和。
解法: 前缀和 + 贪心 / 动态规划 - 维护当前连续和 cur_sum，
      若 cur_sum < 0 则重新从当前元素开始（舍去负累加和）。
      同时维护全局最大 ans。时间 O(n)，空间 O(1)。
"""


def maxSubArray(nums: list[int]) -> int:
    """
    贪心: cur_sum 记录以当前位置结尾的最大子序和。
    若 cur_sum < 0，则从下一个位置重新开始。
    """
    ans = nums[0]
    cur_sum = 0
    for num in nums:
        cur_sum = max(cur_sum + num, num)
        ans = max(ans, cur_sum)
    return ans


if __name__ == "__main__":
    print(maxSubArray([-2, 1, -3, 4, -1, 2, 1, -5, 4]))  # 6 (4,-1,2,1)
    print(maxSubArray([1]))                              # 1
    print(maxSubArray([5, 4, -1, 7, 8]))               # 23
