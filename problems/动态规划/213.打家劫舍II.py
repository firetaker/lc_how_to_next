#!/usr/bin/env python3
"""
213. 打家劫舍 II (House Robber II)

你是一个专业的小偷，计划偷窃沿街的房屋。与上一题不同的是，
这里的房屋都围成一圈，这意味着第一间房屋和最后一间房屋是相邻的。

给定一个代表每间房屋存放金额的非负整数数组 nums，
计算你今晚能够偷窃到的最高金额。

示例：
输入: nums = [2,3,2]
输出: 3
解释: 你不能偷窃编号为 0 和 2 的房屋，因为它们是相邻的。
     所以偷窃 1号房屋 (金额 = 3) 。

动态规划思路：
- 由于第一间和最后一间不能同时偷，分两种情况：
  1. 不偷第一间: 考虑 [1:]
  2. 不偷最后一间: 考虑 [:-1]
- 取两种情况的最大值

时间复杂度: O(n)
空间复杂度: O(1)
"""


def rob(nums: list[int]) -> int:
    """计算环状情况下能偷窃到的最高金额

    Args:
        nums: 每间房屋的金额（环状排列）

    Returns:
        最高偷窃金额
    """
    if not nums:
        return 0
    if len(nums) == 1:
        return nums[0]

    def rob_linear(nums_list: list[int]) -> int:
        """线性情况下的打家劫舍"""
        if not nums_list:
            return 0
        if len(nums_list) == 1:
            return nums_list[0]

        prev2 = 0
        prev1 = nums_list[0]

        for i in range(1, len(nums_list)):
            current = max(prev1, prev2 + nums_list[i])
            prev2 = prev1
            prev1 = current

        return prev1

    # 两种情况取最大
    return max(rob_linear(nums[1:]), rob_linear(nums[:-1]))


if __name__ == "__main__":
    # 测试用例1: [2,3,2]
    assert rob([2, 3, 2]) == 3

    # 测试用例2: [1,2,3,1]
    assert rob([1, 2, 3, 1]) == 4

    # 测试用例3: [1,2,3]
    assert rob([1, 2, 3]) == 3

    print("所有测试用例通过!")
