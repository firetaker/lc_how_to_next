#!/usr/bin/env python3
"""
152. 乘积最大子数组 (Maximum Product Subarray)

给你一个整数数组 nums，请你找出数组中乘积最大的连续子数组（子数组最少包含一个元素），
并返回该子数组的乘积。

示例：
输入: nums = [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 的乘积最大，为 6。

动态规划思路：
- 需要同时维护最大值和最小值（因为负数会使最小变最大）
- max_dp[i] 表示以 i 结尾的最大乘积
- min_dp[i] 表示以 i 结尾的最小乘积
- max_dp[i] = max(nums[i], max_dp[i-1]*nums[i], min_dp[i-1]*nums[i])
- min_dp[i] = min(nums[i], max_dp[i-1]*nums[i], min_dp[i-1]*nums[i])

时间复杂度: O(n)
空间复杂度: O(1) 优化
"""


def max_product(nums: list[int]) -> int:
    """计算乘积最大的子数组

    Args:
        nums: 整数数组

    Returns:
        最大乘积
    """
    if not nums:
        return 0

    result = nums[0]
    max_dp = nums[0]  # 当前最大值
    min_dp = nums[0]  # 当前最小值

    for i in range(1, len(nums)):
        # 乘以当前数之前先保存旧值
        old_max = max_dp
        max_dp = max(nums[i], max_dp * nums[i], min_dp * nums[i])
        min_dp = min(nums[i], old_max * nums[i], min_dp * nums[i])
        result = max(result, max_dp)

    return result


if __name__ == "__main__":
    # 测试用例1: [2,3,-2,4]
    assert max_product([2, 3, -2, 4]) == 6

    # 测试用例2: 全负数
    assert max_product([-2, -3, -1]) == 6

    # 测试用例3: 有0
    assert max_product([-2, 0, -1]) == 0

    print("所有测试用例通过!")
