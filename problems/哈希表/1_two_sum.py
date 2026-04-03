#!/usr/bin/env python3
"""
1. 两数之和 (Two Sum)
题目: 给定数组 nums 和目标值 target，找出和为目标值的两个数的下标。

算法: 哈希表边遍历边存储
时间复杂度: O(n)
空间复杂度: O(n)
"""

def two_sum(nums: list[int], target: int) -> list[int]:
    """
    使用哈希表一次遍历完成查找。
    对于每个元素，检查 target - num 是否已在哈希表中。
    如果存在，直接返回两个下标；如果不存在，将当前元素及其下标存入哈希表。
    """
    seen = {}
    for i, num in enumerate(nums):
        complement = target - num
        if complement in seen:
            return [seen[complement], i]
        seen[num] = i
    return []

if __name__ == "__main__":
    # 测试用例
    result = two_sum([2, 7, 11, 15], 9)
    print(f"输入: nums=[2,7,11,15], target=9 -> 输出: {result}")  # 预期: [0,1]
    
    result = two_sum([3, 2, 4], 6)
    print(f"输入: nums=[3,2,4], target=6 -> 输出: {result}")  # 预期: [1,2]
    
    result = two_sum([3, 3], 6)
    print(f"输入: nums=[3,3], target=6 -> 输出: {result}")  # 预期: [0,1]
    
    result = two_sum([1, 5, 3, 7], 10)
    print(f"输入: nums=[1,5,3,7], target=10 -> 输出: {result}")  # 预期: [1,3] 或 [2,3]
