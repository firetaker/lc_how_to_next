#!/usr/bin/env python3
"""
128. 最长连续序列 (Longest Consecutive Sequence)
题目: 给定未排序整数数组，找出最长连续序列的长度。

算法: 使用 Set 存储所有数字，只从序列起点开始扩展（num-1 不存在）
时间复杂度: O(n)
空间复杂度: O(n)
"""

def longest_consecutive(nums: list[int]) -> int:
    """
    核心思想：
    1. 将所有数字放入 Set，便于 O(1) 查找
    2. 对于每个数字，如果 num-1 不存在，说明这是一个序列的起点
    3. 只从起点开始向后扩展计数，避免重复计算
    4. 最终得到最长序列长度
    """
    num_set = set(nums)
    longest = 0
    
    for num in num_set:
        # 只从序列起点开始扩展
        if num - 1 not in num_set:
            current = num
            streak = 1
            while current + 1 in num_set:
                current += 1
                streak += 1
            longest = max(longest, streak)
    
    return longest

if __name__ == "__main__":
    # 测试用例
    result = longest_consecutive([100, 4, 200, 1, 3, 2])
    print(f"输入: [100, 4, 200, 1, 3, 2] -> 输出: {result}")  # 预期: 4 (序列: 1,2,3,4)
    
    result = longest_consecutive([0, 3, 7, 2, 5, 8, 4, 6, 0, 1])
    print(f"输入: [0, 3, 7, 2, 5, 8, 4, 6, 0, 1] -> 输出: {result}")  # 预期: 9 (0-9连续)
    
    result = longest_consecutive([])
    print(f"输入: [] -> 输出: {result}")  # 预期: 0
    
    result = longest_consecutive([1, 2, 3, 4, 5])
    print(f"输入: [1, 2, 3, 4, 5] -> 输出: {result}")  # 预期: 5
