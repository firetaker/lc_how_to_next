#!/usr/bin/env python3
"""
LeetCode #128: 最长连续序列
题目: 给定一个未排序的整数数组，找出最长连续序列的长度。
解法: 哈希集合 - 将所有元素加入 Set，遍历每个元素作为起点，
      只从连续序列的最小元素开始扩展，从而避免重复遍历。
      时间 O(n)，空间 O(n)。
"""


def longest_consecutive(nums: list[int]) -> int:
    """
    Set + 起点检测: 将所有数加入集合，遍历每个数时检查是否是起点
    （即 num-1 不在集合中），如果是则向后扩展统计长度。
    """
    if not nums:
        return 0
    num_set = set(nums)
    longest = 0
    for num in num_set:
        # 只从连续序列的最小元素开始
        if num - 1 not in num_set:
            cur = num
            cur_len = 1
            while cur + 1 in num_set:
                cur += 1
                cur_len += 1
            longest = max(longest, cur_len)
    return longest


if __name__ == "__main__":
    # 测试用例
    print(longest_consecutive([100, 4, 200, 1, 3, 2]))  # 4
    print(longest_consecutive([0, 3, 7, 2, 5, 8, 4, 6, 0, 1]))  # 9
