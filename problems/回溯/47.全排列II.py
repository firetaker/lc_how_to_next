#!/usr/bin/env python3
"""
47. 全排列 II (Permutations II)
题目: 给定一个可包含重复数字的序列，返回所有不重复的全排列。
算法: 回溯 + 排序 + 剪枝
时间复杂度: O(n! * n)
空间复杂度: O(n)
"""

def permuteUnique(nums):
    result = []
    path = []
    used = [False] * len(nums)
    nums.sort()  # 排序用于去重
    
    def backtrack():
        if len(path) == len(nums):
            result.append(path[:])
            return
        for i in range(len(nums)):
            if used[i]:
                continue
            # 剪枝：相同元素不能重复使用
            if i > 0 and nums[i] == nums[i - 1] and not used[i - 1]:
                continue
            used[i] = True
            path.append(nums[i])
            backtrack()
            path.pop()
            used[i] = False
    
    backtrack()
    return result

if __name__ == "__main__":
    # 测试用例1
    print(permuteUnique([1, 1, 2]))
    # 输出: [[1,1,2], [1,2,1], [2,1,1]]
    
    # 测试用例2
    print(permuteUnique([1, 2, 3]))
    # 输出: 6个排列
    
    # 测试用例3
    print(permuteUnique([2, 2, 1, 1]))
    # 输出: 12个排列
