#!/usr/bin/env python3
"""
78. 子集 (Subsets)
题目: 给你一个整数数组 nums ，返回该数组所有可能的子集（幂集）。子集不能包含重复元素。
算法: 回溯
时间复杂度: O(2^n)
空间复杂度: O(n)
"""

def subsets(nums):
    result = []
    path = []
    
    def backtrack(start):
        result.append(path[:])
        for i in range(start, len(nums)):
            path.append(nums[i])
            backtrack(i + 1)
            path.pop()
    
    backtrack(0)
    return result

if __name__ == "__main__":
    # 测试用例1
    print(subsets([1, 2, 3]))
    # 输出: [[], [1], [1,2], [1,2,3], [1,3], [2], [2,3], [3]]
    
    # 测试用例2
    print(subsets([0]))
    # 输出: [[], [0]]
    
    # 测试用例3
    print(subsets([1, 2, 3, 4]))
    # 输出: 16个子集
