#!/usr/bin/env python3
"""
300. 最长递增子序列 (Longest Increasing Subsequence)

给你一个整数数组 nums，找到其中最长严格递增子序列的长度。
子序列是由数组派生而来的序列，通过删除一些元素（或不删除）而不改变其余元素的顺序。

示例：
输入: nums = [10,9,2,5,3,7,101,18]
输出: 4
解释: 最长递增子序列是 [2,3,7,101]，长度是 4。

动态规划思路：
- dp[i] 表示以第 i 个元素结尾的最长递增子序列长度
- dp[i] = max(dp[j] + 1) for j in [0, i-1] if nums[j] < nums[i]
- 初始条件: dp[i] = 1

时间复杂度: O(n^2)
空间复杂度: O(n)

进阶：可以用二分查找优化到 O(nlogn)
"""


def length_of_lis(nums: list[int]) -> int:
    """计算最长递增子序列的长度

    Args:
        nums: 整数数组

    Returns:
        最长递增子序列的长度
    """
    if not nums:
        return 0

    n = len(nums)
    dp = [1] * n  # dp[i] 表示以 nums[i] 结尾的 LIS 长度

    for i in range(n):
        for j in range(i):
            if nums[j] < nums[i]:
                dp[i] = max(dp[i], dp[j] + 1)

    return max(dp)


if __name__ == "__main__":
    # 测试用例1: 普通情况
    assert length_of_lis([10, 9, 2, 5, 3, 7, 101, 18]) == 4

    # 测试用例2: 全降序
    assert length_of_lis([5, 4, 3, 2, 1]) == 1

    # 测试用例3: 全升序
    assert length_of_lis([1, 2, 3, 4, 5]) == 5

    print("所有测试用例通过!")
