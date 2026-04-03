#!/usr/bin/env python3
"""
53. 最大子数组和 (Maximum Subarray)

给定一个整数数组 nums，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例：
输入: [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

动态规划思路：
- dp[i] 表示以第 i 个元素结尾的最大子数组和
- dp[i] = max(dp[i-1] + nums[i], nums[i])
- 最终答案为 max(dp[i])

时间复杂度: O(n)
空间复杂度: O(1) (优化后)
"""


def max_sub_array(nums: list[int]) -> int:
    """计算最大子数组和

    Args:
        nums: 整数数组

    Returns:
        最大子数组和
    """
    if not nums:
        return 0

    # 空间优化：从O(n)降到O(1)
    prev = nums[0]      # dp[i-1]
    max_result = nums[0]  # 全局最大

    for i in range(1, len(nums)):
        # dp[i] = max(dp[i-1] + nums[i], nums[i])
        current = max(prev + nums[i], nums[i])
        max_result = max(max_result, current)
        prev = current

    return max_result


if __name__ == "__main__":
    # 测试用例1: 普通情况
    assert max_sub_array([-2, 1, -3, 4, -1, 2, 1, -5, 4]) == 6

    # 测试用例2: 全正数
    assert max_sub_array([1, 2, 3, 4, 5]) == 15

    # 测试用例3: 全负数
    assert max_sub_array([-1, -2, -3, -4]) == -1

    print("所有测试用例通过!")
