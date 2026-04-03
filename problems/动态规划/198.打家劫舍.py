#!/usr/bin/env python3
"""
198. 打家劫舍 (House Robber)

你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有现金，
但相邻的房屋装有防盗系统，如果两间相邻的房屋在同一晚上被闯入，会自动报警。

给定一个代表每间房屋存放金额的非负整数数组 nums，
计算你今晚能够偷窃到的最高金额。

示例：
输入: [1,2,3,1]
输出: 4
解释: 偷窃 1号房屋 (金额 = 1) 和 3号房屋 (金额 = 3)，偷窃总金额 = 1 + 3 = 4。

动态规划思路：
- dp[i] 表示偷窃第 i 间房屋能获得的最高金额
- dp[i] = max(dp[i-1], dp[i-2] + nums[i])
- dp[i-1]: 不偷第i间
- dp[i-2] + nums[i]: 偷第i间

时间复杂度: O(n)
空间复杂度: O(1)
"""


def rob(nums: list[int]) -> int:
    """计算能偷窃到的最高金额

    Args:
        nums: 每间房屋的金额

    Returns:
        最高偷窃金额
    """
    if not nums:
        return 0
    if len(nums) == 1:
        return nums[0]

    # 空间优化：从O(n)降到O(1)
    prev2 = 0   # dp[i-2]
    prev1 = nums[0]  # dp[i-1]

    for i in range(1, len(nums)):
        current = max(prev1, prev2 + nums[i])
        prev2 = prev1
        prev1 = current

    return prev1


if __name__ == "__main__":
    # 测试用例1: [1,2,3,1]
    assert rob([1, 2, 3, 1]) == 4

    # 测试用例2: [2,7,9,3,1]
    assert rob([2, 7, 9, 3, 1]) == 12

    # 测试用例3: 全为0
    assert rob([0, 0, 0]) == 0

    print("所有测试用例通过!")
