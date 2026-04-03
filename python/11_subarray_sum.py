#!/usr/bin/env python3
"""
LeetCode #560: 和为 K 的子数组
题目: 给定一个整数数组和一个目标值 k，返回子数组（连续）和为 k 的个数。
解法: 前缀和 + 哈希表 - 使用前缀和快速计算任意子数组和，
      用哈希表记录前缀和出现次数。遍历时查找 (prefix_sum - k)
      是否在哈希表中，即当前前缀和减去之前某个前缀和等于 k。
      时间 O(n)，空间 O(n)。
"""


def subarray_sum(nums: list[int], k: int) -> int:
    """
    前缀和 + 哈希表: pre_sum[i] = nums[0]+...+nums[i-1]。
    子数组 [j, i-1] 的和 = pre_sum[i] - pre_sum[j]。
    因此 pre_sum[i] - k = pre_sum[j] 时，区间和为 k。
    """
    count = 0
    pre_sum = 0
    pre_count = {0: 1}  # 前缀和0出现1次（空数组）
    for num in nums:
        pre_sum += num
        if pre_sum - k in pre_count:
            count += pre_count[pre_sum - k]
        pre_count[pre_sum] = pre_count.get(pre_sum, 0) + 1
    return count


if __name__ == "__main__":
    # 测试用例
    print(subarray_sum([1, 1, 1], 2))       # 2
    print(subarray_sum([1, 2, 3], 3))       # 2 ([1,2] 和 [3])
