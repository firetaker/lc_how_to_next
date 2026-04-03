#!/usr/bin/env python3
"""
416. 分割等和子集 (Partition Equal Subset Sum)

给你一个只包含正整数的非空数组 nums，请你判断是否可以将这个数组分成两个子集，
使得两个子集的元素和相等。

示例：
输入: nums = [1,5,11,5]
输出: true
解释: 可以分割成 [1,5,5] 和 [11]。

动态规划思路：
- 问题转化为：是否可以从数组中挑选一些元素，使得它们的和等于 sum/2
- 转换为 0-1 背包问题
- dp[i] 表示是否能凑成和 i
- for num in nums: for i in range(target, num-1, -1): dp[i] = dp[i] or dp[i-num]

时间复杂度: O(n * sum/2)
空间复杂度: O(sum/2)
"""


def can_partition(nums: list[int]) -> bool:
    """判断是否可以分割成两个和相等的子集

    Args:
        nums: 正整数数组

    Returns:
        如果可以分割返回 True，否则返回 False
    """
    total = sum(nums)
    if total % 2 != 0:
        return False

    target = total // 2

    # dp[i] 表示是否能凑成和 i
    dp = [False] * (target + 1)
    dp[0] = True

    for num in nums:
        # 0-1 背包，从后往前遍历
        for i in range(target, num - 1, -1):
            dp[i] = dp[i] or dp[i - num]

    return dp[target]


if __name__ == "__main__":
    # 测试用例1: [1,5,11,5]
    assert can_partition([1, 5, 11, 5]) == True

    # 测试用例2: [1,2,3,5]
    assert can_partition([1, 2, 3, 5]) == False

    # 测试用例3: [1,1]
    assert can_partition([1, 1]) == True

    print("所有测试用例通过!")
