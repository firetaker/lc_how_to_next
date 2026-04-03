#!/usr/bin/env python3
"""
LeetCode #238: 除自身以外数组的乘积
题目: 给定整数数组，返回答案数组，其中 answer[i] = 除 nums[i] 以外所有元素的乘积。
解法: 前后缀分解 - answer[i] = prefix[i-1] * suffix[i+1]。
      两次遍历：第一次累计前缀积，第二次累计后缀积并合并。
      时间 O(n)，空间 O(1)（输出数组外只用常数空间）。
"""


def productExceptSelf(nums: list[int]) -> list[int]:
    """
    前后缀分解: prefix[i] = nums[0]*...*nums[i-1]（不含 i）
                suffix[i] = nums[i+1]*...*nums[n-1]（不含 i）
    answer[i] = prefix[i] * suffix[i]
    优化：suffix 直接在结果数组上从右向左累计。
    """
    n = len(nums)
    answer = [1] * n
    # 前缀积
    prefix = 1
    for i in range(n):
        answer[i] = prefix
        prefix *= nums[i]
    # 后缀积（从右向左乘入）
    suffix = 1
    for i in range(n - 1, -1, -1):
        answer[i] *= suffix
        suffix *= nums[i]
    return answer


if __name__ == "__main__":
    print(productExceptSelf([1, 2, 3, 4]))          # [24, 12, 8, 6]
    print(productExceptSelf([-1, 1, 0, -3, 3]))    # [0, 0, 9, 0, 0]
